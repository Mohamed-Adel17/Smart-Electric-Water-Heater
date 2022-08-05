/*
 * Segment.h
 *
 *  Author: M.Tharwat
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_math.h"
#include "MemMap.h"
#include <util/delay.h>

/******************************** Segment Config ********************************/
#define	 SEGMENT_PORT		PORTB
#define	 ENABLE_PORT		PORTA
#define		EN1				1     
#define		EN2				0    
/********************************************************************************/


void SegDisplay(u8 n);

void SegDisplay_2(u8 n);

void StopSegment (void);




#endif /* SEGMENT_H_ */