/*
 * HeaterControl.c
 *
 * Created: 8/26/2021 3:10:44 PM
 *  Author: Mohamed Adel
 */ 
#include "HeaterControl.h"


void Heater_Control(void)
{
	static u16 tempArr[10] ={0};
	static u8 Index =0;
	u8 avgTemp = 0;
	tempArr[Index] = LM35_Read_Temp();
	if(Index<9)
	{
		Index++;
		return;
	}
	else if(Index==9)
	{
		u16 sumTemp=0;
		for (u8 counter=0;counter<=9;counter++)
		{
			sumTemp+=tempArr[counter];
		}
		avgTemp = sumTemp/10;
		Index=0;
	}
	
	u8 temp_set = EEPROM_ReadByte(0x54,0x00);
	
	if((avgTemp > temp_set)&&(avgTemp - temp_set >= 5))
	{
		HeatingCooling_Cooler(HIGH_ON);
		HeatingCooling_Heater(LOW_OFF);
	}else if ((avgTemp < temp_set)&&(temp_set - avgTemp >= 5))
	{
		HeatingCooling_Heater(HIGH_ON);
		HeatingCooling_Cooler(LOW_OFF);
	}else
	{
		HeatingCooling_Heater(LOW_OFF);
		HeatingCooling_Cooler(LOW_OFF);
	}
}

void HeaterStop(void)
{
	HeatingCooling_Heater(LOW_OFF);
	HeatingCooling_Cooler(LOW_OFF);
	HeatingCooling_Stop();
}