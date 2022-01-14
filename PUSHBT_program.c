/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


#include "PUSHBT_interface.h"
#include "PUSHBT_private.h"
#include "PUSHBT_config.h"


sint8_t PushBt_init(uint8_t Port , uint8_t Pin , uint8_t mode)
{
	if(Pin>7)
			{
				return -1;
			}
			else
			{
				switch(Port)
				{
				case PORTA: DIO_SetPinDircection(PORTA,Pin,INPUT);	break;
				case PORTB: DIO_SetPinDircection(PORTB,Pin,INPUT);	break;
				case PORTC: DIO_SetPinDircection(PORTC,Pin,INPUT);	break;
				case PORTD: DIO_SetPinDircection(PORTD,Pin,INPUT);	break;
				default: return -1;
				}

				if(mode == PULL_DOWN)
				{
					DIO_SetPinValue(Port,Pin,0);
					return 1;
				}
				else if (mode == PULL_UP)
				{
					DIO_SetPinValue(Port,Pin,1);
					return 1;
				}
				else return -1;
			}
}

sint8_t PushBt_GetState(uint8_t Port , uint8_t Pin , uint8_t *PinState)
{
	if(Pin>7)
		{
			return -1;
		}
		else
		{
			switch(Port)
			{
			case PORTA: DIO_GetPinVal(PORTA,Pin,PinState);	break;
			case PORTB: DIO_GetPinVal(PORTB,Pin,PinState);	break;
			case PORTC: DIO_GetPinVal(PORTC,Pin,PinState);	break;
			case PORTD: DIO_GetPinVal(PORTD,Pin,PinState);	break;
			default: return -1;
			}
			PushBt_debunncing( Port ,  Pin , PinState);
			return 1;
		}
}

sint8_t PushBt_debunncing(uint8_t Port , uint8_t Pin , uint8_t *varible)
{
	if(Pin>7)
	{
		return -1;
	}
	else
	{

			static uint8_t State = 0;
			static uint32_t highCounter = 0;
			static uint32_t lowCounter = 0;
			static uint8_t retVal = 0;
			DIO_GetPinVal(Port,Pin,&State);
			uint8_t check ;
			DIO_GetPinVal(Port,Pin,&check);
			switch (State)
			{
			case 0:
				retVal = 0;
				if(DIO_GetPinVal(Port,Pin,&check) == 1)

					State = 2;
				break;

			case 1:
				DIO_GetPinVal(Port,Pin,&check);
				retVal = 1;
				if( check== 0)
					State = 2;
				break;

			case 2:
				DIO_GetPinVal(Port,Pin,&check);
				if ( check == 1)
				{
					highCounter ++;
					lowCounter = 0;
				}

				else if (check == 0)
				{
					lowCounter ++;
					highCounter = 0;
				}
				if (highCounter == 200)
				{
					State = 1;
					highCounter = 0;
				}
				else if (lowCounter == 200)
				{
					State = 0;
					lowCounter = 0;
				}
				break;
			}
				*varible = retVal;
				return 1;
	}

}
