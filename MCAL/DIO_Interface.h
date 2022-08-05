


#ifndef DIO_H_
#define DIO_H_

#include "STD_TYPES.h"
#include "MemMap.h"
#include "BIT_math.h"

typedef enum {
	OUTPUT,
	INFREE,
	INPULLUP
	}DIO_PinStatus_type;
	
typedef enum {
	PINA0 = 0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
	}DIO_Pin_type;
	
typedef enum {
	PA,
	PB,
	PC,
	PD
	}DIO_Port_type;
	
typedef enum {
	LOW = 0,
	HIGH
	}DIO_Voltage_type;

void DIO_InitPin (DIO_Pin_type pin,DIO_PinStatus_type status);
void DIO_WritePin (DIO_Pin_type pin,DIO_Voltage_type volt);
DIO_Voltage_type DIO_ReadPin (DIO_Pin_type pin);
void DIO_TogglePin (DIO_Pin_type pin);

void DIO_InitPort (DIO_Port_type port,DIO_PinStatus_type status);
void DIO_WritePort (DIO_Port_type port,u8 value);

void DIO_Init(void);

const DIO_PinStatus_type PinStatusArray[TOTAL_PINS];

#endif /* DIO_H_ */