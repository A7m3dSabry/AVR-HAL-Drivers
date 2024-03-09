/*
 * EXTI.c
 *
 *  Created on: Apr 22, 2022
 *  Author: Ahmed
 */

#include "EXTI.h"

void INT0_INIT(void)
{
	MCUCR |= (1<<ISC01) ; // Falling Edge
	GICR |= (1<<INT0) ; // INT0 Enable
}

void INT1_INIT(void)
{
	MCUCR |= (1<<ISC11) | (1<<ISC10) ; // Rising Edge
	GICR |= (1<<INT1) ; // INT1 Enable
}

void INT2_INIT(void)
{
	MCUCSR &= ~(1<<ISC2) ; // Falling Edge
	GICR |= (1<<INT2); // INT2 Enable
}
