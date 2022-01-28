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
	LED_Init(LED0);
	LED_Init(LED1);
	LED_ON(LED0);
	PushBt_init(BTN0);
	PushBt_init(BTN1);

	uint8_t u8_previous=0;
	while(1)
	{
		PushBt_GetState(BTN0,&x);
		if(x==1)
		{
			if(x ==1 && u8_previous ==0)
			{
				LED_TOGGLE(LED1);
			}

		}
		u8_previous =x;
	}
}
