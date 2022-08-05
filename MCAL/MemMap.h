/*
 * MemMap.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "STD_TYPES.h"

/************************************* DIO *************************************/
#define  PINA			( *(volatile u8*) 0x39 )
#define  DDRA			( *(volatile u8*) 0x3A )
#define  PORTA			( *(volatile u8*) 0x3B )

#define  PINB			( *(volatile u8*) 0x36 )
#define  DDRB			( *(volatile u8*) 0x37 )
#define  PORTB			( *(volatile u8*) 0x38 )

#define  PINC			( *(volatile u8*) 0x33 )
#define  DDRC			( *(volatile u8*) 0x34 )
#define  PORTC			( *(volatile u8*) 0x35 )

#define  PIND			( *(volatile u8*) 0x30 )
#define  DDRD			( *(volatile u8*) 0x31 )
#define  PORTD			( *(volatile u8*) 0x32 )
/*******************************************************************************/

/************************************* ADC *************************************/
#define  ADMUX			( *(volatile u8*) 0x27 )
#define  MUX0		0
#define  MUX1		1
#define  MUX2		2
#define  MUX3		3
#define  MUX4		4
#define	 ADLAR		5
#define  REFS0		6
#define  REFS1		7

#define  ADCSRA			( *(volatile u8*) 0x26 )
#define  ADPS0		0
#define  ADPS1		1
#define  ADPS2		2
#define  ADIE		3
#define  ADIF		4
#define	 ADATE		5
#define  ADSC		6
#define  ADEN		7

#define  ADCH			( *(volatile u8*) 0x25 )
#define  ADCL			( *(volatile u8*) 0x24 )

#define  ADC			( *(volatile u16*) 0x24 )
/*******************************************************************************/

/****************************** External Interrupt *****************************/
#define MCUCSR			( *(volatile u8*) 0x54 )
#define ISC2		6

#define MCUCR			( *(volatile u8*) 0x55 )
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define GICR			( *(volatile u8*) 0x5B )
#define INT1		7
#define INT0		6
#define INT2		5

#define GIFR			( *(volatile u8*) 0x5A )
#define INTF1		7
#define INTF0		6
#define INTF2		5

/****************************** Interrupt Vectors ******************************/

/* External Interrupt Request 0 */
#define INT0_vect				__vector_1
/* External Interrupt Request 1 */
#define INT1_vect				__vector_2
/* External Interrupt Request 2 */
#define INT2_vect				__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect			__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect			__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect			__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect			__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define UART_RX_vect			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect				__vector_16
/* EEPROM Ready */
#define EE_RDY_vect				__vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20

#define BAD_vect				__vector_default

/***************************** Interrupt Functions *****************************/

#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)
#define reti()  __asm__ __volatile__ ("reti" ::)
#define ret()  __asm__ __volatile__ ("ret" ::)

#define ISR_NOBLOCK    __attribute__((interrupt))
#define ISR_NAKED      __attribute__((naked))


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/*******************************************************************************/

/****************************** I2C Protocol (TWI) *****************************/

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWBR		  ( *(volatile u8*) 0x20 )
#define TWSR		  ( *(volatile u8*) 0x21 )
#define TWAR		  ( *(volatile u8*) 0x22 )
#define TWDR		  ( *(volatile u8*) 0x23 )
#define TWCR		  ( *(volatile u8*) 0x56 )


/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

/*******************************************************************************/

/**************************** EEPROM Control Register **************************/
/* EEPROM Control Register */
#define EECR	( *(volatile u8*) 0x3C )

#define    EERIE        3
#define    EEMWE        2
#define    EEWE         1
#define    EERE         0

/* EEPROM Data Register */
#define EEDR	( *(volatile u8*) 0x3D )

/* EEPROM Address Register */
#define EEAR	( *(volatile u16*) 0x3E)
#define EEARL	( *(volatile u8*) 0x3E)
#define EEARH	( *(volatile u8*) 0x3F)
/*******************************************************************************/


#endif /* MEMMAP_H_ */