/*
 * LM35.c
 *
 * Created: 8/26/2021 2:28:24 PM
 *  Author: Mohamed Adel
 */

#include "LM35.h"
#include "ADC.h"

u16 LM35_Read_Temp(void)
{
	ADC_INIT();
	u16 temp = ADC_u16ReadData(ADC_CHANNEL)/2.04 ; /*to get the exact temperature*/
	return temp;
} 
