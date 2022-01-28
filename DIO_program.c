/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_Registers.h"
#include "DIO_private.h"
#include "DIO_config.h"


/************************************************************************
 * Set Pin direction from any port
 * INPUT : PORT name , PIN number , (OUTPUT or INPUT)
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPinDircection(uint8_t PORT , uint8_t PIN , uint8_t Mode)
{
	if(PIN >7)
	{
		return -1;
	}
	else
	{
		if(Mode == OUTPUT)
		{
			switch(PORT)
					{
					case DIO_PORTA:
						SET_BIT(DDRA,PIN);
						return 1;
						break;
					case DIO_PORTB:
						SET_BIT(DDRB,PIN);
						return 1;
						break;
					case DIO_PORTC:
						SET_BIT(DDRC,PIN);
						return 1;
						break;
					case DIO_PORTD:
						SET_BIT(DDRD,PIN);
						return 1;
						break;
					default:
						return -2;
					}
		}
		else if( Mode == INPUT)
			{
			switch(PORT)
				{
			case DIO_PORTA:
				CLR_BIT(DDRA,PIN);
					return 1;
					break;
			case DIO_PORTB:
				CLR_BIT(DDRB,PIN);
					return 1;
					break;
			case DIO_PORTC:
				CLR_BIT(DDRC,PIN);
					return 1;
					break;
			case DIO_PORTD:
				CLR_BIT(DDRD,PIN);
					return 1;
					break;
			default:
					return -2;
				}
			}
		else if (Mode == INPUT_PULLUP)
		{
			switch(PORT)
				{
			case DIO_PORTA:
				CLR_BIT(DDRA,PIN);
				SET_BIT(PORTA,PIN);
					return 1;
					break;
			case DIO_PORTB:
				CLR_BIT(DDRB,PIN);
				SET_BIT(PORTB,PIN);
					return 1;
					break;
			case DIO_PORTC:
				CLR_BIT(DDRC,PIN);
				SET_BIT(PORTC,PIN);
					return 1;
					break;
			case DIO_PORTD:
				CLR_BIT(DDRD,PIN);
				SET_BIT(PORTD,PIN);
					return 1;
					break;
			default:
					return -2;
				}
		}
		else
		{
			return -3;
		}
	}
}

/************************************************************************
 * Set Port direction
 * INPUT : PORT name , (OUTPUT or INPUT)
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPortDirection(uint8_t PORT, uint8_t Mode)
{
	switch(PORT)
	{
	case DIO_PORTA:
		if(Mode == OUTPUT)
		{
			DDRA =0xff;
			return 1;
		}
		else if (Mode == INPUT)
		{
			DDRA = 0x00;
			return 1;
		}
		else
			return -1;
		break;
	case DIO_PORTB:
			if(Mode == OUTPUT)
			{
				DDRB =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DDRB = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	case DIO_PORTC:
			if(Mode == OUTPUT)
			{
				DDRC =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DDRC = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	case DIO_PORTD:
			if(Mode == OUTPUT)
			{
				DDRD =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DDRD = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	default:
			return -1;
	}
}


/************************************************************************
 * Set Pin value from any port
 * INPUT : PORT name , PIN number , value
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPinValue(uint8_t PORT , uint8_t PIN , uint8_t value)
{
	if(PIN >7)
		{
			return -1;
		}
		else
		{
			if(value == HIGH)
			{
				switch(PORT)
						{
						case DIO_PORTA:
							SET_BIT(PORTA,PIN);
							return 1;
							break;
						case DIO_PORTB:
							SET_BIT(PORTB,PIN);
							return 1;
							break;
						case DIO_PORTC:
							SET_BIT(PORTC,PIN);
							return 1;
							break;
						case DIO_PORTD:
							SET_BIT(PORTD,PIN);
							return 1;
							break;
						default:
							return -2;
						}
			}
			else if( value == LOW)
				{
				switch(PORT)
					{
				case DIO_PORTA:
					CLR_BIT(PORTA,PIN);
						return 1;
						break;
				case DIO_PORTB:
					CLR_BIT(PORTB,PIN);
						return 1;
						break;
				case DIO_PORTC:
					CLR_BIT(PORTC,PIN);
						return 1;
						break;
				case DIO_PORTD:
					CLR_BIT(PORTD,PIN);
						return 1;
						break;
				default:
						return -2;
					}
				}
			else
			{
				return -3;
			}
		}
}


/************************************************************************
 * Set port value
 * INPUT : PORT name  , value
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPortValue(uint8_t PORT , uint8_t value)
{
	switch(PORT)
		{
		case DIO_PORTA:
			PORTA = value;
				return 1;
				break;
		case DIO_PORTB:
				PORTB = value;
				return 1;
				break;
		case DIO_PORTC:
				PORTC = value;
				return 1;
				break;
		case DIO_PORTD:
				PORTD = value;
				return 1;
				break;
		default:
				return -1;
		}
}


/************************************************************************
 * get Pin value from any port
 * INPUT : PORT name , PIN number , variable to store the data
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_GetPinVal(uint8_t PORT , uint8_t PIN , uint8_t * val)
{

	if(PIN >7)
			{
				return -1;
			}
			else
			{
					switch(PORT)
							{
							case DIO_PORTA:
								*val =  GET_BIT(PINA,PIN);
								return 1;
								break;
							case DIO_PORTB:
								*val =  GET_BIT(PINB,PIN);
								return 1;
								break;
							case DIO_PORTC:
								*val =  GET_BIT(PINC,PIN);
								return 1;
								break;
							case DIO_PORTD:
								*val =  GET_BIT(PIND,PIN);
								return 1;
								break;
							default:
								return -2;
							}
			}
}


/************************************************************************
 * Toggle Pin value of any port
 * INPUT : PORT name , PIN number
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_TogglePin(uint8_t PORT , uint8_t PIN )
{
	if(PIN >7)
		{
			return -1;
		}
		else
		{
				switch(PORT)
						{
						case DIO_PORTA:
							TOGGLE_BIT(PORTA,PIN);
							return 1;
							break;
						case DIO_PORTB:
							TOGGLE_BIT(PORTB,PIN);
							return 1;
							break;
						case DIO_PORTC:
							TOGGLE_BIT(PORTC,PIN);
							return 1;
							break;
						case DIO_PORTD:
							TOGGLE_BIT(PORTD,PIN);
							return 1;
							break;
						default:
							return -2;
						}

		}
}

