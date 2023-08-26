/*
 * App.h
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
#ifndef APP_H_
#define APP_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* =============================================================
 * 							Includes
 * =============================================================*/
#include "../HAL/LED/LED.h"
#include <util/delay.h>
#include "../MCAL/Interrupts/atmega32_Interrupts.h"
#include "../HAL/LCD/AVR_LCD.h"

/* =============================================================
 * 							Definitions
 * =============================================================*/
#define  SECONDS_5   5000

#define NB_OF_DELAY_LOOP_REPETITON 50
#define NB_OF_MILLISECONDS_FOR_DELAY 20

#define NB_OF_SECONDS_DELAY 5

#define COUNTDOWN_BEGIN '5'

/* =============================================================
 * 				        Function Prototypes
 * =============================================================*/

void RoutineRED(void);
void CarMode(void);
void PedestrianMode(void);
void RG_Delay(uint8 sec);
void Y_Delay();
void Yellow_Blink(void);
void Pedestrian_CountDown();
void Pedestrian_Routine();

#endif /* APP_H_ */