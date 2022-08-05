/*
 ******************************************Electric Water Heater Project******************************************
 * Breakin Point Required Project
 * Created: 8/25/2021 12:46:07 PM
 * Authors : ********Mohamed Adel********
			 ********Mohamed Tharwat*****
 */ 

#include "STD_TYPES.h"
#include "BIT_math.h"
#include "LM35.h"
#include "HeatingCooling.h"
#include "Scheduler.h"
#include "HeaterControl.h"
#include "ControlTemp.h"
#include "EXInterrupt.h"
#include "EX_EEPROM.h"
#include "I2C.h"
#include "DIO_Interface.h"

#define OnOff_Button PIND5
#define Adc_Channel PINA7
#define PRESSED 0


int main(void)
{
	/*Initialization of Scheduler and I2C */
	/**************************************************************/
    SCH_init();
	I2C_Init();
	/**************************************************************/

	/*DIO PORTS & PINS Initialization*/
	/**************************************************************/
	DIO_InitPort(PA,OUTPUT);
	DIO_InitPort(PB,OUTPUT);
	DIO_InitPin(OnOff_Button,INFREE);
	DIO_InitPin(Adc_Channel,INFREE);
	/**************************************************************/
	
	/*Adding Tasks To Scheduler with the required Delay and Period*/
	/**************************************************************/
	SCH_Add_Task(Temp_Control,1,1);
	SCH_Add_Task(Heater_Control,2,10);			  /*every 100ms will execute*/
	SCH_Add_Task(HeatingCooling_HeatingLED,3,100); /*every 1s will execute*/
	SCH_Add_Task(TempFlag_Control,4,10);
	/**************************************************************/
	
	/*Configuration of External Interrupts 0&1*/
	/**************************************************************/
	EXI_SetCallBack(EXT_INT0,ISR_UpBUTTON);
	EXI_TriggerEdge(EXT_INT0,RISING_EDGE);
	EXI_Enable(EXT_INT0);
	
	EXI_SetCallBack(EXT_INT1,ISR_DownBUTTON);
	EXI_TriggerEdge(EXT_INT1,RISING_EDGE);
	EXI_Enable(EXT_INT1);
	/**************************************************************/
	
	

    while (1) 
    {
		while(DIO_ReadPin(PIND5) != PRESSED) /*to check the state of The OnOff Button, if NOT PRESSED, will remain in this loop*/
		{
			StopEveryThing();
			SCH_Stop();
		}
		SCH_Start();
		EXI_EnableAll();
		SCH_Dispatcher();
    }
}
