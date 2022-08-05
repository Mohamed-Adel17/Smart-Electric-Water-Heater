
#include "DIO_Interface.h"

void DIO_InitPin (DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port;
	u8 pin_num;
	
	port = pin/8;
	pin_num = pin%8;
	
	switch (status)
	{
		case OUTPUT :
			switch (port)
			{
				case PA :
					SET_BIT (DDRA,pin_num);
				break;
				case PB :
					SET_BIT (DDRB,pin_num);
				break;
				case PC :
					SET_BIT (DDRC,pin_num);
				break;
				case PD :
					SET_BIT (DDRD,pin_num);
				break;	
			}
		break;
			
		case INFREE :
			switch (port)
			{
				case PA :
					CLEAR_BIT (DDRA,pin_num);
					CLEAR_BIT (PORTA,pin_num);
				break;
				case PB :
					CLEAR_BIT (DDRB,pin_num);
					CLEAR_BIT (PORTB,pin_num);
				break;
				case PC :
					CLEAR_BIT (DDRC,pin_num);
					CLEAR_BIT (PORTC,pin_num);
				break;
				case PD :
					CLEAR_BIT (DDRD,pin_num);
					CLEAR_BIT (PORTD,pin_num);
				break;
			}
		break;
			
		case INPULLUP :
			switch (port)
			{
				case PA :
					CLEAR_BIT (DDRA,pin_num);
					SET_BIT (PORTA,pin_num);
				break;
				case PB :
					CLEAR_BIT (DDRB,pin_num);
					SET_BIT (PORTB,pin_num);
				break;
				case PC :
					CLEAR_BIT (DDRC,pin_num);
					SET_BIT (PORTC,pin_num);
				break;
				case PD :
					CLEAR_BIT (DDRD,pin_num);
					SET_BIT (PORTD,pin_num);
				break;
			}
		break;
	}
}

void DIO_WritePin (DIO_Pin_type pin,DIO_Voltage_type volt)
{
	DIO_Port_type port;
	u8 pin_num;
	
	port = pin/8;
	pin_num = pin%8;
	
	if (volt == HIGH)
	{
		switch (port)
			{
				case PA :
					SET_BIT (PORTA,pin_num);
				break;
				case PB :
					SET_BIT (PORTB,pin_num);
				break;
				case PC :
					SET_BIT (PORTC,pin_num);
				break;
				case PD :
					SET_BIT (PORTD,pin_num);
				break;	
			}		
	}
	
	else if (volt == LOW)
	{
		switch (port)
			{
				case PA :
					CLEAR_BIT (PORTA,pin_num);
				break;
				case PB :
					CLEAR_BIT (PORTB,pin_num);
				break;
				case PC :
					CLEAR_BIT (PORTC,pin_num);
				break;
				case PD :
					CLEAR_BIT (PORTD,pin_num);
				break;	
			}
	}
}


DIO_Voltage_type DIO_ReadPin (DIO_Pin_type pin)
{
	DIO_Port_type port, volt = 0;
	u8 pin_num;
	
	port = pin/8;
	pin_num = pin%8;
	
	switch (port)
	{
		case PA :
			volt = GET_BIT (PINA,pin_num);
		break;
		case PB :
			volt = GET_BIT (PINB,pin_num);
		break;
		case PC :
			volt = GET_BIT (PINC,pin_num);
		break;
		case PD :
			volt = GET_BIT (PIND,pin_num);
		break;
	}
	return volt ;	
}


void DIO_TogglePin (DIO_Pin_type pin)
{
	DIO_Port_type port;
	u8 pin_num;
	
	port = pin/8;
	pin_num = pin%8;
	
	switch (port)
	{
		case PA :
			TOGGLE_BIT (PORTA,pin_num);
		break;
		case PB :
			TOGGLE_BIT (PORTB,pin_num);
		break;
		case PC :
			TOGGLE_BIT (PORTC,pin_num);
		break;
		case PD :
			TOGGLE_BIT (PORTD,pin_num);
		break;
	}
}


void DIO_InitPort (DIO_Port_type port,DIO_PinStatus_type status)
{
	switch (status)
	{
		case OUTPUT :
			switch (port)
			{
				case PA :
					DDRA = 0xFF;
				break;
				case PB :
					DDRB = 0xFF;
				break;
				case PC :
					DDRC = 0xFF;
				break;
				case PD :
					DDRD = 0xFF;
				break;
			}
		break;
		
		case INFREE :
			switch (port)
			{
				case PA :
					DDRA = 0x00;
					PORTA = 0x00;
				break;
				case PB :
					DDRB = 0x00;
					PORTB = 0x00;
				break;
				case PC :
					DDRC = 0x00;
					PORTC = 0x00;
				break;
				case PD :
					DDRD = 0x00;
					PORTD = 0x00;
				break;
			}
		break;
		
		case INPULLUP :
			switch (port)
			{
				case PA :
					DDRA = 0x00;
					PORTA = 0xFF;
				break;
				case PB :
					DDRB = 0x00;
					PORTB = 0xFF;
				break;
				case PC :
					DDRC = 0x00;
					PORTC = 0xFF;
				break;
				case PD :
					DDRD = 0x00;
					PORTD = 0xFF;
				break;
			}
		break;
	}
}


void DIO_WritePort (DIO_Port_type port,u8 value)
{
	switch (port)
	{
		case PA :
			PORTA = value;
		break;
		case PB :
			PORTB = value;
		break;
		case PC :
			PORTC = value;
		break;
		case PD :
			PORTD = value;
		break;
	}
}


void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0 ; i<TOTAL_PINS ; i++)
	{
		DIO_InitPin(i,PinStatusArray[i]);
	}
}