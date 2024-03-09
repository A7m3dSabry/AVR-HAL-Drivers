/*
 * Seven_Segment.c
 *
 *  Created on: Apr 22, 2022
 *  Author: Ahmed
 */

#include "Seven_Segment.h"

void SevSeg_WriteNumber(unsigned char number)
{
	PORTC = (PORTC & 0xF0) | (number & 0x0F) ;
}

void SevSeg_Sec1_Enable(void)
{
	PORTA |= (1<<0);
}

void SevSeg_Sec1_Disable(void)
{
	PORTA &= ~(1<<0);
}

void SevSeg_Sec2_Enable(void)
{
	PORTA |= (1<<1);
}

void SevSeg_Sec2_Disable(void)
{
	PORTA &= ~(1<<1);
}

void SevSeg_Min1_Enable(void)
{
	PORTA |= (1<<2);
}

void SevSeg_Min1_Disable(void)
{
	PORTA &= ~(1<<2);
}

void SevSeg_Min2_Enable(void)
{
	PORTA |= (1<<3);
}

void SevSeg_Min2_Disable(void)
{
	PORTA &= ~(1<<3);
}

void SevSeg_Hour1_Enable(void)
{
	PORTA |= (1<<4);
}

void SevSeg_Hour1_Disable(void)
{
	PORTA &= ~(1<<4);
}

void SevSeg_Hour2_Enable(void)
{
	PORTA |= (1<<5);
}

void SevSeg_Hour2_Disable(void)
{
	PORTA &= ~(1<<5);
}
