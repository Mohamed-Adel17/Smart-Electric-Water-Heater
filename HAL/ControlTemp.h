/*
 * ControlTemp.h
 *
 * Created: 8/27/2021 1:53:19 AM
 *  Author: M.tharwat
 */ 


#ifndef CONTROLTEMP_H_
#define CONTROLTEMP_H_

#include "STD_TYPES.h"
#include "Segment.h"
#include "LM35.h"
#include "EX_EEPROM.h"
#include "EXInterrupt.h"
#include "HeaterControl.h"
#include "DIO_Interface.h"

#define OFF_PORT 0xFF
#define FIVEsecCYCLES 89
#define MIN_TEMP 35
#define MAX_TEMP 75

void ISR_UpBUTTON (void);
void ISR_DownBUTTON (void);
void TempFlag_Control(void);
void Temp_Control(void);
void StopEveryThing(void);



#endif /* CONTROLTEMP_H_ */