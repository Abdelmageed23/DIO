/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef PUSHBT_interface_H
#define PUSHBT_interface_H



typedef enum
{
	BTN0,
	BTN1,

}BTN_Num_t;


sint8_t PushBt_init(BTN_Num_t BTN_NUM);
sint8_t PushBt_GetState(BTN_Num_t BTN_NUM ,uint8_t *PinState);
sint8_t PushBt_debunncing(BTN_Num_t BTN_NUM , uint8_t *varible);


























/* Pin values */
#define HIGH 1
#define LOW  0

/* input mode */
#define PULL_DOWN	1
#define PULL_UP		2



/* LED PORTs*/

#define PUSHBT_PORTA 1
#define PUSHBT_PORTB 2
#define PUSHBT_PORTC 3
#define PUSHBT_PORTD 4



/* LED PINs  */
#define PUSHBT_PIN0   0
#define PUSHBT_PIN1   1
#define PUSHBT_PIN2   2
#define PUSHBT_PIN3   3
#define PUSHBT_PIN4   4
#define PUSHBT_PIN5   5
#define PUSHBT_PIN6   6
#define PUSHBT_PIN7   7


#endif
