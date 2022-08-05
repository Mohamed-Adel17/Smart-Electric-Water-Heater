/*
 * I2C.c
 *
 *  Author: M.Tharwat
 */ 

#include "I2C.h"

/*	Master Mode
	SCL Freq = 400Khz
	Interrupt Disabled
*/

void I2C_Init(void)
{
	/* Setting Scl Freq = 400Khz when F_CPU = 8Mhz */
	TWBR = 2 ;
	
	// Generate Acknowledge Pulse: On
	// TWI Interrupt: Off
	TWCR = 0x04;
	TWSR = 0x00 ;
	TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));
	
}

void TWI_SendStartCond(void)
{
	/* Save Values of TWEN & TWIE and Clear other Bits */
	TWCR &= 0x07;
	/* Start Cond to be transmitted and Clear TWINT Flag */
	TWCR |= (1<<TWSTA) | (1<<TWINT);
	
	 // Wait for Start Cond to be transmitted
	while ((TWCR & (1<<TWINT)) == 0);
}

void TWI_SendStopCond(void)
{
	/* Save Values of TWEN & TWIE and Clear other Bits */
	TWCR &= 0x07;
	/* Stop Cond to be transmitted and Clear TWINT Flag */
	TWCR |= (1<<TWSTO) | (1<<TWINT) | (1 << TWEN);
	
}

void TWI_WriteData(u8 data)
{
	/* Save Values of TWEN & TWIE and Clear other Bits */
	TWCR &= 0x07;
	
	TWDR = data;
	
	/* Set TWINT Flag Value And I2C Start Operation */
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	// Wait for Data to be transmitted
	while ((TWCR & (1<<TWINT)) == 0);
}

u8 TWI_ReadData_ACK(void)
{
	/* Save Values of TWEN & TWIE and Clear other Bits */
	TWCR &= 0x07;
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	
	// Wait for Data to be Rx
	while ((TWCR & (1<<TWINT)) == 0);
	
	return TWDR;
}

u8 TWI_ReadData_NACK(void)
{
	/* Save Values of TWEN & TWIE and Clear other Bits */
	TWCR &= 0x07;
	TWCR |= (1<<TWINT) | (1<<TWEN);
	
	// Wait for Data to be Rx
	while ((TWCR & (1<<TWINT)) == 0);
	
	return TWDR;
}

u8 TWI_GetStatus(void)
{
	return (TWSR & 0xF8);
}

/********************************************************************************/


void I2C_WritwByte(u8 SlaveAddress, u8 InternalReg , u8 Data)
{
	// Send Start Cond
	TWI_SendStartCond();
	if (TWI_GetStatus() != TW_START_Cond)
	{
		//ERROR
	}
	
	// Send SLA + W AND Wait ACK
	TWI_WriteData((SlaveAddress<<1) | WRITEMODE);
	if (TWI_GetStatus() != TW_SLA_WR_ACK)
	{
		//ERROR
	}
	
	// Send Register Address AND Wait ACK
	TWI_WriteData(InternalReg);
	if (TWI_GetStatus() != TW_DATA_WR_ACK)
	{
		//ERROR
	}
	
	//Byte to be written AND Wait ACK
	TWI_WriteData(Data);
	if (TWI_GetStatus() != TW_DATA_WR_ACK)
	{
		//ERROR
	}
	
	// Send Stop Cond
	TWI_SendStopCond();
	
}

u8 I2C_ReadByte(u8 SlaveAddress, u8 InternalReg)
{
	u8 DataRx = 0;
	
	// Send Start Cond
	TWI_SendStartCond();
	if (TWI_GetStatus() != TW_START_Cond)
	{
		//ERROR
	}
	
	// Send SLA + W AND Wait ACK
	TWI_WriteData((SlaveAddress<<1) | WRITEMODE);
	if (TWI_GetStatus() != TW_SLA_WR_ACK)
	{
		//ERROR
	}
	
	// Send Register Address AND Wait ACK
	TWI_WriteData(InternalReg);
	if (TWI_GetStatus() != TW_DATA_WR_ACK)
	{
		//ERROR
	}
	
	// Send Rep Start
	TWI_SendStartCond();
	if (TWI_GetStatus() != TW_REP_START)
	{
		//ERROR
	}
	
	// Send SLA + R AND Wait ACK
	TWI_WriteData((SlaveAddress<<1) | READMODE);
	if (TWI_GetStatus() != TW_SLA_RD_ACK)
	{
		//ERROR
	}
	
	// Read Data + with NACK
	DataRx = TWI_ReadData_NACK();
	if (TWI_GetStatus() != TW_DATA_RD_NACK)
	{
		//ERROR
	}
	
	// Send Stop Cond
	TWI_SendStopCond();
	
	return DataRx;
}