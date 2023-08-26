/*
 * Interrupts_atmega32.h
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

#ifndef ATMEGA32_INTERRUPTS_H
#define ATMEGA32_INTERRUPTS_H
/* =============================================================
 * 							Includes
 * =============================================================*/
#include "../../Commons/std_types.h"
#include "../../MCAL/DIO/atmega32_DIO.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/

/*MISRA C - 2012 Rule 7.2 All unsigned constants are followed by a U suffix to avoid ambiguity*/

#define GLOBAL_INT_ENABLE   		1U
#define GLOBAL_INT_DISABLE        	0U
									 
#define INT1_LOW_LEVEL 				0U
#define INT1_ANY_CHANGE 			1U
#define INT1_FALLING_EDGE 			2U
#define INT1_RISING_EDGE 			3U
									 
#define INT0_LOW_LEVEL 				0U
#define INT0_ANY_CHANGE 			1U
#define INT0_FALLING_EDGE 			2U
#define INT0_RISING_EDGE 			3U
									 
#define INT2_FALLING_EDGE			0U
#define INT2_RISING_EDGE			1U

#define INT1_ENABLE					0x80U
#define INT0_ENABLE					0x40U
#define INT2_ENABLE					0x20U
#define INT1F                       7U

#define INT0_Vector                __vector_1
#define INT1_Vector                __vector_2
/* =============================================================
 * 							Function Prototypes
 * =============================================================*/
void Global_Interrupt_Init() ;

void Ext_Int0_Enable(uint8 Mode);

void Ext_Int0_Disable();

void Ext_Int1_Enable();

void Ext_Int1_SetFlag();

void Ext_Int1_Disable();

void Ext_Int2_Enable(uint8 Mode);

void Ext_Int2_Disable();

void CallbacktoPedestrianMode(void (*Callback_ptr)(void));

/* =============================================================
 * 				Global Shared Variables and Pointers
 * =============================================================*/

extern void (*Callback_ptr)();

#define GLOBAL_INTERRUPT_ENABLE_BIT (0x80U)

#endif /* INTERRUPTS_ATMEGA32_H_ */
