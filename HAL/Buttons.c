/*
 * Buttons.c
 *
 *  Author: M.Tharwat
 */ 

#include "Buttons.h"

void Butt_Init(void)
{
	DIO_InitPin(UpButton,INPULLUP);
	DIO_InitPin(DownButton,INPULLUP);
	DIO_InitPin(NF_Button,INPULLUP);
	
}

DIO_Voltage_type Butt_Read(u8 button)
{
	DIO_Voltage_type r ;
	r = DIO_ReadPin(button);
	
	return r;
}
u8 Flag=0, SetTemp = 60,SensorTemp,c1=0,c2=0,counter;

void ISR_UpButton (void)
{
	if (Flag == 0)
	{
		SegDisplay_2 (SetTemp);
		Flag++;
	}
	else if (Flag == 1)
	{
		if (SetTemp<75)
		{
			SetTemp += 5;
		}
		EEPROM_WriteByte(0x54,0x00,SetTemp);
		c1++;
	}
}

void ISR_DownButton (void)
{
	if (Flag == 0)
	{
		SegDisplay_2 (SetTemp);
		Flag++;
	}
	else if (Flag == 1)
	{
		if (SetTemp > 35)
		{
			SetTemp -= 5;
		}
		EEPROM_WriteByte(0x54,0x00,SetTemp);
		c1++;
	}
}
