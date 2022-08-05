/*
 * Buttons.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "STD_TYPES.h"
#include "BIT_math.h"
#include "MemMap.h"
#include "DIO_Interface.h"


/******************************** Button Config ********************************/
#define	 UpButton			PINC0
#define	 DownButton			PINC1
#define	 NF_Button			PINC2
/********************************************************************************/

void Butt_Init(void);


DIO_Voltage_type Butt_Read(u8 button);





#endif /* BUTTONS_H_ */