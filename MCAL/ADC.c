/*
 * ADC.c
 *
 * Created: 07/02/2021 03:29:01 م
 *  Author: Mu
 */ 

#include "STD_TYPES.h"
#include "BIT_math.h"
#include "ADC.h"
#include "avr/interrupt.h"
#include "GPIO.h"

#define Vref 5
volatile u16 Volt;
ISR(ADC_vect)
{
	Volt = ADC_R;
}

void ADC_INIT(void)
{
	SET_BIT(ADCSRA_R,ADEN_R);  //enable ADC
	
	/*set the prescaler of ADC to 64*/
	SET_BIT(ADCSRA_R,ADPS2_R);
	SET_BIT(ADCSRA_R,ADPS1_R);
		
	SET_BIT(ADMUX_R,REFS0_R);  //set ADC voltage from AVCC
	SET_BIT(ADCSRA_R,ADIE_R);  //enable ADC interrupt
	
	//sei(); //we will enable it in the sch_start function
}

u16 ADC_u16ReadData(u8 channel)
{
	ADMUX_R &= 0xE0;
    ADMUX_R |= channel;
    
    SET_BIT(ADCSRA_R,ADSC_R); //start the conversion process
    
    return Volt ;
}

f32 ADC_f32ReadVoltage(u8 channel)
{
	
	u16 voltage = ADC_u16ReadData(channel);
	f32 Vin  = (Vref*voltage)/1024.0;
	return Vin ;
}


 
