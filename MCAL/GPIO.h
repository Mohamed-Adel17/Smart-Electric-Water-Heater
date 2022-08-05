/*
 * GPIO.h
 *
 * Created: 1/18/2021 6:10:39 AM
 *  Author: Mohamed Adel
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "STD_TYPES.h"


/*------------------------------------------------------------*/
/**define I/O registers**/
#define PINA_R			*( (volatile u8 *) (0x39))
#define DDRA_R			*( (volatile u8 *) (0x3A))
#define PORTA_R	    	*( (volatile u8 *) (0x3B))


#define PINB_R			*( (volatile u8 *) (0x36))
#define DDRB_R			*( (volatile u8 *) (0x37))
#define PORTB_R			*( (volatile u8 *) (0x38))


#define PINC_R			*( (volatile u8 *) (0x33))
#define DDRC_R			*( (volatile u8 *) (0x34))
#define PORTC_R			*( (volatile u8 *) (0x35))


#define PIND_R			*( (volatile u8 *) (0x30))
#define DDRD_R			*( (volatile u8 *) (0x31))
#define PORTD_R			*( (volatile u8 *) (0x32))
/*------------------------------------------------------------*/


/**define PORT indicies**/
#define xPORTA 0
#define xPORTB 1
#define xPORTC 2
#define xPORTD 3
/*------------------------------------------------------------*/


/**define some constants**/
#define INPUT   0
#define OUTPUT  1

#define LOW   0
#define HIGH  1

#define  PORT_LOW  0
#define  PORT_HIGH 255

#define START_VALUE 0
/*------------------------------------------------------------*/


/**define PIN numbers**/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/*------------------------------------------------------------*/



/**Functions prototypes**/
void GPIO_voidSetPortDirection (u8 PORT_Index , u8 PORT_direction);
void GPIO_voidSetPortPinDirection (u8 PORT_Index , u8 PIN_number , u8 PIN_direction);
void GPIO_voidSetPortPinValue (u8 PORT_Index , u8 PIN_number , u8 PIN_value);
void GPIO_voidSetPortValue(u8 PORT_Index , u8 PORT_value);
u8 GPIO_u8GetPortPinValue(u8 PORT_Index , u8 PIN_number);
u8 GPIO_u8GetPortValue(u8 PORT_Index);
/*------------------------------------------------------------*/


#endif /* GPIO_H_ */