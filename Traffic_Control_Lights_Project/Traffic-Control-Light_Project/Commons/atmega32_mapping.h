/*
 * atmega32_mapping.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
 */
/* =============================================================
 * 							File Guard
 * =============================================================*/
#ifndef ATMEGA32_MAPPING_H_
#define ATMEGA32_MAPPING_H_
/* =============================================================
 * 							Includes
 * =============================================================*/

#include "std_types.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/
/*
	REGISTER FOR PORTA, DDRA, PINA
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTA *((volatile uint8 *)0x3B)
#define DDRA  *((volatile uint8 *)0x3A)
#define PINA  *((volatile uint8 *)0x39)


/*
	REGISTER FOR PORTB, DDRB, PINB
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTB *((volatile uint8 *)0x38)
#define DDRB *((volatile uint8 *)0x37)
#define PINB *((volatile uint8 *)0x36)


/*
	REGISTER FOR PORTC, DDRC, PINC
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTC *((volatile uint8 *)0x35)
#define DDRC *((volatile uint8 *)0x34)
#define PINC *((volatile uint8 *)0x33)


/*
	REGISTER FOR PORTD, DDRD, PIND
	1.SET PORT ADDRESS
	2.SET DDR ADDRESS
	3.SET PIN ADDRESS
*/

#define PORTD *((volatile uint8 *)0x32)
#define DDRD *((volatile uint8 *)0x31)
#define PIND *((volatile uint8 *)0x30)


/* =============================================================
 * 							Shared
 * =============================================================*/
#define SREG   *((volatile uint8*) 0x5F)
#define MCUCR  *((volatile uint8*) 0x55)
#define MCUCSR *((volatile uint8*) 0x54)
#define GICR   *((volatile uint8*) 0x5B)
#define GIFR   *((volatile uint8*) 0x5A)

/* =============================================================
 * 							Interrupts
 * =============================================================*/
/* Concatenation Function */
#define VECTOR(x) "%s_" ((x))

/* ISR Body */
#define ISR(vector) \
void ((vector) (void)) __attribute__ ((signal,used, externally_visible)) ; \
void ((vector) (void))

#endif /* ATMEGA32_MAPPING_H_ */
