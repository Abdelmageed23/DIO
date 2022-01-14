/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


/*
 * Initializing LED as OUTPUT
 */
sint8_t LED_Init(uint8_t PORT , uint8_t Pin)
{
	if(Pin>7)
	{
		return -1;
	}
	else
	{
		DIO_SetPinDircection(PORT,Pin,OUTPUT);
	return 1;
	}
}


/*
 * Turn LED ON
 * INPUT : PORT , PIN
 * OUTPUT: 1 if ok -1 if not ok
 */
sint8_t LED_ON(uint8_t PORT , uint8_t Pin)
{
	if(Pin>7)
	{
		return -1;
	}
	else
	{
		DIO_SetPinValue(PORT,Pin,HIGH);
	return 1;
	}
}

/*
 * Turn LED OFF
 * INPUT : PORT , PIN
 * OUTPUT: 1 if ok -1 if not ok
 */
sint8_t LED_OFF(uint8_t PORT , uint8_t Pin)
{
	if(Pin>7)
		{
			return -1;
		}
		else
		{
			DIO_SetPinValue(PORT,Pin,LOW);
			return 1;
		}

}

/*
 * TOGGLE LED
 * INPUT : PORT , PIN
 * OUTPUT: 1 if ok -1 if not ok
 */
sint8_t LED_TOGGLE(uint8_t PORT , uint8_t Pin)
{
	if(Pin>7)
			{
				return -1;
			}
			else
			{
			DIO_TogglePin(PORT,Pin);
			return 1;
			}
}
