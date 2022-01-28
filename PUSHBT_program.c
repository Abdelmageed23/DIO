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


sint8_t PushBt_init(BTN_Num_t BTN_NUM)
{
	switch(BTN_NUM)
		{
		case BTN0 :
				DIO_SetPinDircection(BTN0_PORT,BTN0_PIN,OUTPUT);
				return OK;
			break;
		case BTN1 :
				DIO_SetPinDircection(BTN1_PORT,BTN1_PIN,OUTPUT);
				return OK;
			break;
		default:
			return NOK;
			break;
		}
}

sint8_t PushBt_GetState(BTN_Num_t BTN_NUM ,uint8_t *PinState)
{
			switch(BTN_NUM)
			{
			case BTN0 :
				DIO_GetPinVal(BTN0_PORT,BTN0_PIN,PinState);	break;
			case BTN1 :
				DIO_GetPinVal(BTN1_PORT,BTN1_PIN,PinState);	break;
			default:
				return -1;
			}
			PushBt_debunncing(BTN_NUM , PinState);
			return 1;

}

sint8_t PushBt_debunncing(BTN_Num_t BTN_NUM , uint8_t *varible)
{
	uint8_t Port=0,Pin=0;
	switch(BTN_NUM)
	{
	case BTN0:
		Port =BTN0_PORT;
		Pin = BTN0_PIN;
		break;
	case BTN1:
			Port =BTN1_PORT;
			Pin = BTN1_PIN;
		break;
	default:
		return -1;
	}
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


