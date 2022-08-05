/*
 * EXInterrupt.c
 *
 *  Author: M.Tharwat
 */ 

#include "EXInterrupt.h"

static void(*Fptr_INT0)(void) = NULLPTR;
static void(*Fptr_INT1)(void) = NULLPTR;
static void(*Fptr_INT2)(void) = NULLPTR;

void EXT_EnableGlobalInt (void)
{
	sei();
}

void EXI_Enable(EXInterruptSource_type interrupt)
{
	switch (interrupt)
	{
		case EXT_INT0 :
			SET_BIT(GICR,INT0);
		break;
		case EXT_INT1 :
			SET_BIT(GICR,INT1);
		break;
		case EXT_INT2 :
			SET_BIT(GICR,INT2);
		break;
	}
}

void EXI_Disable(EXInterruptSource_type interrupt)
{
	switch (interrupt)
	{
		case EXT_INT0 :
			CLEAR_BIT(GICR,INT0);
		break;
		case EXT_INT1 :
			CLEAR_BIT(GICR,INT1);
		break;
		case EXT_INT2 :
			CLEAR_BIT(GICR,INT2);
		break;
	}
}
void EXI_DisableAll(void)
{
	EXI_Disable(EXT_INT0);
	EXI_Disable(EXT_INT1);
}
void EXI_EnableAll(void)
{
	EXI_Enable(EXT_INT0);
	EXI_Enable(EXT_INT1);
}
void EXI_TriggerEdge(EXInterruptSource_type interrupt,TriggerEdge_type edge)
{
	switch (interrupt)
	{
		case EXT_INT0 :
			switch (edge)
			{
				case LOW_LEVEL :
					CLEAR_BIT (MCUCR,ISC00);
					CLEAR_BIT (MCUCR,ISC01);
				break;
				
				case ANY_LOGIC_CHANGE :
					SET_BIT (MCUCR,ISC00);
					CLEAR_BIT (MCUCR,ISC01);
				break;
				
				case FALLING_EDGE :
					SET_BIT (MCUCR,ISC01);
					CLEAR_BIT (MCUCR,ISC00);
				break;
				
				case RISING_EDGE :
					SET_BIT (MCUCR,ISC01);
					SET_BIT (MCUCR,ISC00);
				break;
			}
		break;
		
		case EXT_INT1 :
			switch (edge)
			{
				case LOW_LEVEL :
					CLEAR_BIT (MCUCR,ISC10);
					CLEAR_BIT (MCUCR,ISC11);
				break;
				
				case ANY_LOGIC_CHANGE :
					SET_BIT (MCUCR,ISC10);
					CLEAR_BIT (MCUCR,ISC11);
				break;
				
				case FALLING_EDGE :
					SET_BIT (MCUCR,ISC11);
					CLEAR_BIT (MCUCR,ISC10);
				break;
				
				case RISING_EDGE :
					SET_BIT (MCUCR,ISC11);
					SET_BIT (MCUCR,ISC10);
				break;
			}
		break;
		
		case EXT_INT2 :
			switch (edge)
			{
				case LOW_LEVEL :
				break;
				
				case ANY_LOGIC_CHANGE :
				break;
				
				case FALLING_EDGE :
					CLEAR_BIT (MCUCSR,ISC2);
				break;
				
				case RISING_EDGE :
					SET_BIT (MCUCSR,ISC2);
				break;
			}
		break;
	}
}

void EXI_SetCallBack(EXInterruptSource_type interrupt , void(*pf_local)(void))
{
	switch (interrupt)
	{
		case EXT_INT0 :
			Fptr_INT0 =pf_local ;
		break;
		case EXT_INT1 :
			Fptr_INT1 =pf_local ;
		break;
		case EXT_INT2 :
			Fptr_INT2 =pf_local ;
		break;
	}
}


ISR(INT0_vect)
{
	if (Fptr_INT0 !=  NULLPTR )
	Fptr_INT0();
}

ISR(INT1_vect)
{
	if (Fptr_INT1 != NULLPTR )
	Fptr_INT1();
}

ISR(INT2_vect)
{
	if (Fptr_INT2 != NULLPTR )
	Fptr_INT2();
}