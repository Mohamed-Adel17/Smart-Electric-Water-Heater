/*
 * HeatingCooling.c
 *
 * Created: 8/26/2021 2:34:37 PM
 *  Author: Mohamed Adel
 */ 

#include "HeatingCooling.h"
#include "BIT_math.h"
#include <avr/io.h>
#define HIGH   1
#define LOW    0
#define TOGGLE 0

u8 flagHeater=0, flagCooler=0;

void HeatingCooling_Heater(u8 State)
{
	switch (State)
	{
		case LOW  : 
					CLEAR_BIT(PORTA,2);
					flagHeater=0;
					break;
		case HIGH : 
					SET_BIT(PORTA,2); 
					flagHeater=1;  
					break;
	}
}
void HeatingCooling_Cooler(u8 State)
{
	switch(State)
	{
		case LOW  : CLEAR_BIT(PORTA,3); 
					flagCooler=0;
					break;
		case HIGH : 
					SET_BIT(PORTA,3);
					flagCooler=1;
					break;
	}
}

void HeatingCooling_HeatingLED(void)
{
	if ((flagHeater==1)&&(flagCooler==0))
	{
		TOGGLE_BIT(PORTA,5);
	}else if ((flagHeater==0)&&(flagCooler==1))
	{
		SET_BIT(PORTA,5);
	}else
	{	CLEAR_BIT(PORTA,5);
	}	
}

void HeatingCooling_Stop(void)
{
	CLEAR_BIT(PORTA,5);
}