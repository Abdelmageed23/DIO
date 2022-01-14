/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H



/* LED PORTs*/

#define LED_PORTA 1
#define LED_PORTB 2
#define LED_PORTC 3
#define LED_PORTD 4



/* LED PINs  */
#define LED_PIN0   0
#define LED_PIN1   1
#define LED_PIN2   2
#define LED_PIN3   3
#define LED_PIN4   4
#define LED_PIN5   5
#define LED_PIN6   6
#define LED_PIN7   7




sint8_t LED_Init(uint8_t PORT , uint8_t Pin);
sint8_t LED_ON(uint8_t PORT , uint8_t Pin);
sint8_t LED_OFF(uint8_t PORT , uint8_t Pin);
sint8_t LED_TOGGLE(uint8_t PORT , uint8_t Pin);
#endif


