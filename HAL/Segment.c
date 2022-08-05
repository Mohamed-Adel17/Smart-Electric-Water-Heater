/*
 * Segment.c
 *
 *  Author: M.Tharwat
 */ 

#include "Segment.h"

static u8 SegNumbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
void SegDisplay(u8 n)
{
	SEGMENT_PORT = ~SegNumbers[n];
}





void SegDisplay_2(u8 n)
{
	SET_BIT(ENABLE_PORT,EN1);
	CLEAR_BIT(ENABLE_PORT,EN2);
	
	SEGMENT_PORT = ~SegNumbers[n/10];
	_delay_ms(1);
	
	SET_BIT(ENABLE_PORT,EN2);
	
	CLEAR_BIT(ENABLE_PORT,EN1);
	SEGMENT_PORT = ~SegNumbers[n%10];
	_delay_ms(1);

}

void StopSegment (void)
{
	CLEAR_BIT(ENABLE_PORT,EN1);
	
	CLEAR_BIT(ENABLE_PORT,EN2);
	
}