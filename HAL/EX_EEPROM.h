/*
 * EX_EEPROM.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef EX_EEPROM_H_
#define EX_EEPROM_H_

#include "STD_TYPES.h"
#include "MemMap.h"
#include "BIT_math.h"
#include "I2C.h"

void EEPROM_WriteByte(u8 EEP_Addr, u8 InAddr ,u8 data);
u8 EEPROM_ReadByte(u8 EEP_Addr, u8 InAddr);




#endif /* EX_EEPROM_H_ */