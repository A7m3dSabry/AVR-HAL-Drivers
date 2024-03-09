/*
 * Seven_Segment.h
 *
 *  Created on: Apr 22, 2022
 *  Author: Ahmed
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include <avr/io.h>

void SevSeg_WriteNumber(unsigned char number);

void SevSeg_Sec1_Enable(void);
void SevSeg_Sec1_Disable(void);

void SevSeg_Sec2_Enable(void);
void SevSeg_Sec2_Disable(void);

void SevSeg_Min1_Enable(void);
void SevSeg_Min1_Disable(void);

void SevSeg_Min2_Enable(void);
void SevSeg_Min2_Disable(void);

void SevSeg_Hour1_Enable(void);
void SevSeg_Hour1_Disable(void);

void SevSeg_Hour2_Enable(void);
void SevSeg_Hour2_Disable(void);

#endif /* SEVEN_SEGMENT_H_ */
