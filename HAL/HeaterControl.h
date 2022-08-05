/*
 * HeaterControl.h
 *
 * Created: 8/26/2021 3:11:03 PM
 *  Author: Mohamed Adel
 */ 


#ifndef HEATERCONTROL_H_
#define HEATERCONTROL_H_

#include "STD_TYPES.h"
#include "LM35.h"
#include "HeatingCooling.h"
#include "EX_EEPROM.h"
#define LOW_OFF  0
#define HIGH_ON 1

void Heater_Control(void);
void HeaterStop(void);

#endif /* HEATERCONTROL_H_ */