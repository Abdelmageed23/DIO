/*
 * DIO_Registers.h
 *
 *  Created on: Jan 28, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef DIO_REGISTERS_H
#define DIO_REGISTERS_H


/* REGISTER ADDRESSES FOR PORTA */
#define PORTA		(*(volatile uint8_t*)(0x3B))
#define DDRA		(*(volatile uint8_t*)(0x3A))
#define PINA		(*(volatile uint8_t*)(0x39))

/* REGISTER ADDRESSES FOR PORTB */
#define PORTB		(*(volatile uint8_t*)(0x38))
#define DDRB		(*(volatile uint8_t*)(0x37))
#define PINB		(*(volatile uint8_t*)(0x36))

/* REGISTER ADDRESSES FOR PORTC */
#define PORTC		(*(volatile uint8_t*)(0x35))
#define DDRC		(*(volatile uint8_t*)(0x34))
#define PINC		(*(volatile uint8_t*)(0x33))

/* REGISTER ADDRESSES FOR PORTD */
#define PORTD		(*(volatile uint8_t*)(0x32))
#define DDRD		(*(volatile uint8_t*)(0x31))
#define PIND		(*(volatile uint8_t*)(0x30))


#endif /* DIO_REGISTERS_H_ */
