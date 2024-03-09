/*
 * Timer1.c
 *
 *  Created on: Apr 22, 2022
 *  Author: Ahmed
 */

#include "Timer1.h"

void TIMER1_INIT(void)
{
	
	  /* Configure the timer to be in CTC with following configs
	   *
	   * prescaller = clk/1024
	   * start 		= 0
	   * OCR value	= 1000
	   */

	  /* Expected behaviour : Interrupt every 1 sec*/
	TCCR1A = (1<<FOC1B) ;
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS12) | (1<<CS10) ;
	TCNT1 = 0;

	ICR1 = 1000;
	TIMSK |= (1<<OCIE1B) ;
}

void TIMER1_STOP(void)
{
	/* stop timer by setting its clock to 0 */
	TCCR1B &= (0xF8);
}

void TIMER1_RESUME(void)
{
	/* configure timer clock to clk/1024 again to continue */
	TCCR1B |= (1<<CS12) | (1<<CS10) ;
}
