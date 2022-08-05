/*
 * HeatingCooling.h
 *
 * Created: 8/26/2021 2:34:51 PM
 *  Author: Mohamed Adel
 */ 


#ifndef HEATINGCOOLING_H_
#define HEATINGCOOLING_H_
#include "STD_TYPES.h"

void HeatingCooling_Heater(u8 State);
void HeatingCooling_Cooler(u8 State);
void HeatingCooling_HeatingLED(void);
void HeatingCooling_Stop(void);

#endif /* HEATINGCOOLING_H_ */