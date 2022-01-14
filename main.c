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

	uint8_t u8_previous=0;
	while(1)
	{
		PushBt_GetState(PUSHBT_PORTB,2,&x);
		if(x==1)
		{
			if(x ==1 && u8_previous ==0)
			{
				LED_TOGGLE(LED_PORTB,5);
			}

		}
		u8_previous =x;
	}
}
