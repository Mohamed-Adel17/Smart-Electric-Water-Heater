/*
 * EXInterrupt.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_

#include "MemMap.h"
#include "STD_TYPES.h"
#include "BIT_math.h"

typedef enum {
	EXT_INT0 ,
	EXT_INT1 ,
	EXT_INT2
	}EXInterruptSource_type;
	
typedef enum {
	LOW_LEVEL = 0 ,
	ANY_LOGIC_CHANGE ,
	FALLING_EDGE ,
	RISING_EDGE ,
	}TriggerEdge_type;
	
void EXT_EnableGlobalInt (void);
void EXI_Enable(EXInterruptSource_type interrupt);
void EXI_Disable(EXInterruptSource_type interrupt);
void EXI_TriggerEdge(EXInterruptSource_type interrupt,TriggerEdge_type edge);
void EXI_SetCallBack(EXInterruptSource_type interrupt , void(*pf_local)(void));
void EXI_DisableAll(void);
void EXI_EnableAll(void);



#endif /* EXINTERRUPT_H_ */