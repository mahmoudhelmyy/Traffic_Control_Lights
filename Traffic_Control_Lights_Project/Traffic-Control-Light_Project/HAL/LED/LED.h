
/*
 * Led.h
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

#ifndef LED_H_
#define LED_H_

/* =============================================================
 * 							Includes
 * =============================================================*/

#include "../../MCAL/DIO/atmega32_DIO.h"
#include "../../Commons/std_types.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/
/*MISRA C - 2012 Rule 7.2 All unsigned constants are followed by a U suffix to avoid ambiguity*/


#define LED_BLUE			0U   
#define LED_RED				1U
#define LED_YELLOW			2U
#define LED_GREEN			3U

#define LED_RED_PORT		PORTB_ID
#define LED_RED_PIN			PIN7_ID

#define LED_GREEN_PORT		PORTA_ID
#define LED_GREEN_PIN		PIN4_ID

#define LED_BLUE_PORT		PORTA_ID
#define LED_BLUE_PIN		PIN5_ID

#define LED_YELLOW_PORT		PORTA_ID
#define LED_YELLOW_PIN		PIN6_ID

#define LED_OFF				0U
#define LED_ON				1U

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* =============================================================
 * 							Function Prototypes
 * =============================================================*/

void Led_Init(uint8 Led_Color);
void Led_Init_All(void);
void LED_on(uint8 Led_Color);
void Led_Off(uint8 Led_Color);
void Led_Toggle(uint8 Led_Color);
uint8 Led_Check(uint8 Led_Color);
void Led_All_Off();

#endif /* LED_H_ */
