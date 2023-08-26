/*
 * Led.c
 *
  *  Created on: Aug 20, 2023
  *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
  */

#ifndef LED_C_
#define LED_C_

#include "LED.h"

/*Initialization of all LEDs in the kit used*/
void Led_Init(uint8 Led_Color) {
	switch (Led_Color) {
	case LED_BLUE:
		DIO_setupPinDirection(LED_BLUE_PORT, LED_BLUE_PIN, PIN_OUTPUT);
		DIO_writePin(LED_BLUE_PORT, LED_BLUE_PIN, LOGIC_LOW);
		break;

	case LED_RED:
		DIO_setupPinDirection(LED_RED_PORT, LED_RED_PIN, PIN_OUTPUT);
		DIO_writePin(LED_RED_PORT, LED_RED_PIN, LOGIC_LOW);
		break;

	case LED_YELLOW:
			DIO_setupPinDirection(LED_YELLOW_PORT, LED_YELLOW_PIN, PIN_OUTPUT);
			DIO_writePin(LED_YELLOW_PORT,  LED_YELLOW_PIN, LOGIC_LOW);
		break;

	case LED_GREEN:
				DIO_setupPinDirection(LED_GREEN_PORT,  LED_GREEN_PIN, PIN_OUTPUT);
				DIO_writePin(LED_GREEN_PORT, LED_GREEN_PIN, LOGIC_LOW);
		break;
	default: ;
	/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
	/*Left for future update for error handling*/
	}
}

/*Group Intialization*/
void Led_Init_All(){
	Led_Init(LED_BLUE);
	Led_Init(LED_RED);
	Led_Init(LED_YELLOW);
	Led_Init(LED_GREEN);
}
/*Setting the LED being passed to the function*/
void LED_on(uint8 Led_Color){
	switch (Led_Color) {
	case LED_BLUE:
		DIO_writePin(LED_BLUE_PORT, LED_BLUE_PIN, LOGIC_HIGH);
		break;

	case LED_RED:
		DIO_writePin(LED_RED_PORT, LED_RED_PIN, LOGIC_HIGH);
		break;

	case LED_YELLOW:
		DIO_writePin(LED_YELLOW_PORT,  LED_YELLOW_PIN, LOGIC_HIGH);
		break;

	case LED_GREEN:
		DIO_writePin(LED_GREEN_PORT, LED_GREEN_PIN, LOGIC_HIGH);
		break;
		
	default: ;
	/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
	/*Left for future update for error handling*/
	}
}
void Led_Off(uint8 Led_Color){
	switch (Led_Color) {
	case LED_BLUE:
		DIO_writePin(LED_BLUE_PORT, LED_BLUE_PIN, LOGIC_LOW);
		break;

	case LED_RED:
		DIO_writePin(LED_RED_PORT, LED_RED_PIN, LOGIC_LOW);
		break;

	case LED_YELLOW:
		DIO_writePin(LED_YELLOW_PORT, LED_YELLOW_PIN, LOGIC_LOW);
		break;

	case LED_GREEN:
		DIO_writePin(LED_GREEN_PORT, LED_GREEN_PIN, LOGIC_LOW);
		break;
		
	default: ;
	/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
	/*Left for future update for error handling*/
	}
}


void Led_Toggle(uint8 Led_Color){
	switch (Led_Color) {
	case LED_BLUE:
		DIO_TogglePin(LED_BLUE_PORT, LED_BLUE_PIN);
		break;

	case LED_RED:
		DIO_TogglePin(LED_RED_PORT, LED_RED_PIN);
		break;

	case LED_YELLOW:
		DIO_TogglePin(LED_YELLOW_PORT, LED_YELLOW_PIN);
		break;

	case LED_GREEN:
		DIO_TogglePin(LED_GREEN_PORT, LED_GREEN_PIN);
		break;
		
	default: ;
	/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
	/*Left for future update for error handling*/
	}
}
uint8 Led_Check(uint8 Led_Color){
	uint8 result=FALSE;
	switch (Led_Color) {
	case LED_BLUE:
		result=DIO_readPin(LED_BLUE_PORT, LED_BLUE_PIN);
		break;

	case LED_RED:
		result=DIO_readPin(LED_RED_PORT, LED_RED_PIN);
		break;

	case LED_YELLOW:
		result=DIO_readPin(LED_YELLOW_PORT, LED_YELLOW_PIN);
		break;

	case LED_GREEN:
		result=DIO_readPin(LED_GREEN_PORT, LED_GREEN_PIN);
		break;
		
	default: ;
	/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
	/*Left for future update for error handling*/
	}
	return result;
}

void Led_All_Off(){
	DIO_writePin(LED_BLUE_PORT, LED_BLUE_PIN, LOGIC_LOW);
	DIO_writePin(LED_RED_PORT, LED_RED_PIN, LOGIC_LOW);
	DIO_writePin(LED_YELLOW_PORT, LED_YELLOW_PIN, LOGIC_LOW);
	DIO_writePin(LED_GREEN_PORT, LED_GREEN_PIN, LOGIC_LOW);

}
#endif /* LED_C_ */
