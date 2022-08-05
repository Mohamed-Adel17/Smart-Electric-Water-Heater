/*
 * I2C.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef I2C_H_
#define I2C_H_

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "MemMap.h"
#include "BIT_math.h"

#define WRITEMODE		0x00
#define READMODE		0x01

#define TW_START_Cond				 0x08
#define TW_REP_START				 0x10
#define TW_SLA_WR_ACK				 0x18
#define TW_DATA_WR_ACK				 0x28
#define TW_MT_ARB_LOST				 0x38
#define TW_MR_ARB_LOST				 0x38
#define TW_DATA_RD_NACK				 0x58
#define TW_MR_SLA_NOT_ACK			 0x48
#define TW_MT_SLA_NOT_ACK			 0x20
#define TW_MT_DATA_NOT_ACK			 0x30
#define TW_MR_DATA_ACK				 0x50
#define TW_SLA_RD_ACK				 0x40



void I2C_Init(void);
void TWI_SendStartCond(void);
void TWI_SendStopCond(void);
void TWI_WriteData(u8 data);
u8 TWI_ReadData_ACK(void);
u8 TWI_ReadData_NACK(void);
u8 TWI_GetStatus(void);



void I2C_WritwByte(u8 SlaveAddress, u8 InternalReg , u8 Data);
u8 I2C_ReadByte(u8 SlaveAddress, u8 InternalReg);

#endif /* I2C_H_ */