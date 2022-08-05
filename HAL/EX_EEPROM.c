/*
 * EX_EEPROM.c
 *
 *  Author: M.Tharwat
 */ 

#include "EX_EEPROM.h"


void EEPROM_WriteByte(u8 EEP_Addr, u8 InAddr ,u8 data)
{
	TWI_SendStartCond();
	
	TWI_WriteData((EEP_Addr<<1) | WRITEMODE);
	
	TWI_WriteData(InAddr);
	
	TWI_WriteData(data);
	
	TWI_SendStopCond();
}


u8 EEPROM_ReadByte(u8 EEP_Addr, u8 InAddr)
{
	u8 DataRx = 0;
	
	TWI_SendStartCond();
	
	TWI_WriteData((EEP_Addr<<1) | WRITEMODE);
	
	TWI_WriteData(InAddr);

	TWI_SendStartCond();

	TWI_WriteData((EEP_Addr<<1) | READMODE);

	DataRx = TWI_ReadData_NACK();

	TWI_SendStopCond();
	
	return DataRx;
}