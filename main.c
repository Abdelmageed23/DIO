/*
 * main.c
 *
 *  Created on: Jan 12, 2022
 *      Author: Abdelrahman Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "PUSHBT_interface.h"


void main()
{
	uint8_t x=0;
	LED_Init(LED_PORTB,4);
	LED_Init(LED_PORTB,5);
	LED_ON(LED_PORTB,4);
	PushBt_init(PUSHBT_PORTC,4,PULL_DOWN);
	PushBt_init(PUSHBT_PORTB,2,PULL_DOWN);

	while(1)
	{
		PushBt_GetState(PUSHBT_PORTB,2,&x);
		while(x)
		{
			LED_ON(LED_PORTB,5);
			PushBt_GetState(PUSHBT_PORTB,2,&x);
		}
		LED_OFF(LED_PORTB,5);
	}
}
