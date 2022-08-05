
#include "STD_TYPES.h"
#include "Scheduler.h"
#include "BIT_math.h"
#include <avr/io.h>
#include "avr/interrupt.h"

sTask SCH_TaskArr[SCH_MAX_TASKS];
void SCH_init(void)
{
	u8 i=0;
	for (i = 0; i < SCH_MAX_TASKS; i++)
	  {
		SCH_Delete_Task(i);
	  }
	
	/*timer1 init, 8 MHZ foc , 1024 prescaler*/
	SET_BIT(TIMSK,TOIE1); // set TOIE=1 to enable interrupt at overflow
	
	/*set the pre_scaler to 1024*/
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS12);
    
	//TCNT1 = 65477; // set the start to get 10ms time 
	TCNT1 = 65461; // set the start to get 10ms time , and 7.5ms + about 2.5 ms for the system
}

void SCH_Start(void)
{
	sei();
}



ISR(TIMER1_OVF_vect) /*the update function*/
{
	TCNT1 = 65461;
	
	u8 Index;
	
	for(Index=0; Index < SCH_MAX_TASKS; Index++)
	{
		if (SCH_TaskArr[Index].ptrTask)
		{
		if(SCH_TaskArr[Index].Delay == 0)
		{
			SCH_TaskArr[Index].RunMe ++;
			if (SCH_TaskArr[Index].Period !=0)
			{
				SCH_TaskArr[Index].Delay = SCH_TaskArr[Index].Period;
			}
		}else 
		{
			SCH_TaskArr[Index].Delay -=1;
		}
		}
	}
}


u8 SCH_Add_Task(void (* pFunction)(),
				const u8 DELAY,
				const u16 PERIOD)
{
	u8 Index=0;

    while ((SCH_TaskArr[Index].ptrTask != 0) && (Index < SCH_MAX_TASKS))
		{
			Index++;
		}
	
	SCH_TaskArr[Index].ptrTask = pFunction;
	SCH_TaskArr[Index].Delay = DELAY;
	SCH_TaskArr[Index].Period = PERIOD;
	SCH_TaskArr[Index].RunMe = 0;
		
	return Index;	
}


void SCH_Delete_Task(u8 Index)
{
	SCH_TaskArr[Index].ptrTask =  0x0000;
	SCH_TaskArr[Index].Delay =  0;
	SCH_TaskArr[Index].Period = 0;
	SCH_TaskArr[Index].RunMe =  0;
}


void SCH_Delete_All_Tasks(void)
{
	for (u8 Index=0;Index<SCH_MAX_TASKS;Index++)
	{
		SCH_TaskArr[Index].ptrTask =  0x0000;
		SCH_TaskArr[Index].Delay =  0;
		SCH_TaskArr[Index].Period = 0;
		SCH_TaskArr[Index].RunMe =  0;
	}
}


void SCH_Dispatcher(void)
{
	u8 Index;
	for(Index=0; Index < SCH_MAX_TASKS; Index++)
	{
		if(SCH_TaskArr[Index].RunMe > 0)
		{
			(*SCH_TaskArr[Index].ptrTask)();
			SCH_TaskArr[Index].RunMe-=1;
			
			if(SCH_TaskArr[Index].Period ==0)
			{
				SCH_Delete_Task(Index);
			}
		}	
	}
}

void SCH_Stop(void)
{
	cli();
}									 






