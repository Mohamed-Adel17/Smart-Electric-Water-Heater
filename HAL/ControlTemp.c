/*
 * ControlTemp.c
 *
 * Created: 8/27/2021 1:53:14 AM
 *  Author: Tharwat&Adel
 */ 

#include "ControlTemp.h"


static volatile u8 Flag=0, BlinkFlag=0, LastBlinkFlag=0, SetTemp=0, Blinkcounter=0, For5secCounter=0;

void ISR_UpBUTTON (void)
{
	SetTemp = EEPROM_ReadByte(0x54,0x00);
	if (Flag == 0)
	{
		SegDisplay_2 (SetTemp);
		Flag++;
	}
	else if (Flag == 1)
	{
		if (SetTemp < MAX_TEMP)
		{
			SetTemp += 5;
		}
		EEPROM_WriteByte(0x54,0x00,SetTemp);
		BlinkFlag++;
	}
}

void ISR_DownBUTTON (void)
{
	SetTemp = EEPROM_ReadByte(0x54,0x00);
	if (Flag == 0)
	{
		SegDisplay_2 (SetTemp);
		Flag++;
	}
	else if (Flag == 1)
	{
		if (SetTemp > MIN_TEMP)
		{
			SetTemp -= 5;
		}
		EEPROM_WriteByte(0x54,0x00,SetTemp);
		BlinkFlag++;
	}
}



void TempFlag_Control(void)
{
	if (BlinkFlag == LastBlinkFlag)
	{
		For5secCounter ++;
		Blinkcounter++;
	}
	else
	{
		For5secCounter = 0;
		Blinkcounter =0;
	}
	
	LastBlinkFlag = BlinkFlag;
	
	if (For5secCounter == FIVEsecCYCLES)
	{
		Flag = 0;
		For5secCounter = 0;
		Blinkcounter = 0;
		BlinkFlag = 0;
		LastBlinkFlag = 0;
	}
}

void Temp_Control(void)
{
	
	if (Flag == 0)
		SegDisplay_2 (LM35_Read_Temp());
	
	else if (Flag > 0)
	{
		if(Blinkcounter <= 10)
			SegDisplay_2 (SetTemp);
		else if(Blinkcounter <=20)
				PORTB = OFF_PORT;
		else
			Blinkcounter=0;				
	}
}

void StopEveryThing(void)
{
	HeaterStop();
	StopSegment();
	EXI_DisableAll();
}
