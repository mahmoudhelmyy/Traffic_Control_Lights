/*
 * App.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
 */
#include "App.h"

uint8 Interrupt_Flag = FALSE;
uint8 Return_to_Car_Mode_flag=FALSE;

/*Pointer to the function for the call back*/
void (*Callback_ptr)() = &PedestrianMode;

/*Call Back Function*/
void CallbacktoPedestrianMode(void (*Callback_ptr)(void))
{
	(*Callback_ptr)();
}

void App() {
	/*Interfacing the Button connected to External Interrupt 1 pin to the AVR ATMEGA32*/
	Global_Interrupt_Init(GLOBAL_INT_ENABLE);
	/*External INT1 Button Located in the Keypad Matrix Mode as Row 1 | Port C | Pin5 and Column 4 | Port D | Pin3*/
	/*External INT1 Button is connected to Port D | Pin3 when configured as Direct Mode in the Keypad*/
	Ext_Int1_Enable(INT1_FALLING_EDGE);
	/*LCD initialization for displaying the Mode (Pedestrian or Car)*/
	LCD_init();
	/*Initializing Blue,Red,Yellow and Green LEDs provided on the kit*/
	Led_Init_All();
	/*Car Mode Begin*/
	CarMode();
}

void CarMode() {
	while (1) {
		/*LCD  Refreshing*/
		LCD_clearScreen();
		/*Setting all pins to low to begin a new cycle*/
		Led_All_Off();
		/*LCD will display the mode currently running (Car) as per requirements*/
		LCD_moveCursor(1,8);
		LCD_displayString("CARS");   
		/*New Cycle starting from green as per requirements*/           
		LED_on(LED_GREEN);
		/*Case: If there is no interrupt delay and skip the next if conditions*/
		RG_Delay(NB_OF_SECONDS_DELAY);
		/*Case: If there is an interrupt execute and skip the rest of the cycle */
		if (Return_to_Car_Mode_flag == TRUE) {
			Return_to_Car_Mode_flag = FALSE;
			continue;
		}
		/*There is no interrupt, switch off Green LED and continue Car Mode operation normally*/
		Led_Off(LED_GREEN);
		Yellow_Blink();
		/*Case: If there is no interrupt delay and skip the next if conditions*/
		/*Case: If there is an interrupt execute and skip the rest of the cycle */
		if (Return_to_Car_Mode_flag == TRUE) {
			Return_to_Car_Mode_flag = FALSE;
			continue;
		}
		/*There is no interrupt, continue Car Mode operation normally*/
		LED_on(LED_RED);
		RG_Delay(NB_OF_SECONDS_DELAY);
		if (Return_to_Car_Mode_flag == TRUE) {
			Return_to_Car_Mode_flag = FALSE;
			continue;
		}
		/*There is no interrupt, continue Car Mode operation normally*/
		Led_Off(LED_RED);
	}
}

void RoutineRED(void){                                   
	/*The Logic to be executed when Red light is already ON as per the requirements */
	Pedestrian_Routine();
}
void RoutineGreen(void){                                    
	/*The Logic to be executed when Green light is already ON as per the requirements */
	Yellow_Blink();
	Pedestrian_Routine();
}
void RoutineYellow(void) {                                  
	/*The Logic to be executed when Yellow light is already ON as per the requirements */
	Yellow_Blink();
	Pedestrian_Routine();

}

void Yellow_Blink() {
	/* Variable to display the countdown on the LCD*/
	char countdown = COUNTDOWN_BEGIN;
	LCD_moveCursor(2, 0);
	/*Clear the second row*/
	LCD_displayString("                     ");
	Led_All_Off();
	/* For Loop to blink the Yellow Led and display the countdown on LCD*/
	for (uint8 i = 0; i < NB_OF_SECONDS_DELAY; i++) {
		Led_Toggle(LED_YELLOW);
		LCD_moveCursor(2, 10);
		LCD_displayCharacter(countdown--);
		/* Delay for the yellow Led Blinking*/
		Y_Delay();
		/* Check if an interrupt happened during the delay*/
		if (Return_to_Car_Mode_flag == TRUE) {
			return;
		}
	}
	LCD_moveCursor(2, 0);
	/*Clear the second row*/
	LCD_displayString("                ");
	Led_Off(LED_YELLOW);
}


void RG_Delay(uint8 Seconds) {
	/*Function for displaying a countdown in the red and green led operation period together with the mode currently active*/
	for (uint8 i = 0; i < NB_OF_DELAY_LOOP_REPETITON * Seconds; i++) {
		_delay_ms(NB_OF_MILLISECONDS_FOR_DELAY);
		switch (i) {
		case 0:
			LCD_moveCursor(2, 10);
			LCD_displayCharacter('5');
			/*Printing the countdown in the middle of the LCD screen*/
			break;
		case 50:
			LCD_moveCursor(2, 10);
			LCD_displayCharacter('4');
			/*Printing the countdown in the middle of the LCD screen*/
			break;
		case 100:
			LCD_moveCursor(2, 10);
			LCD_displayCharacter('3');
			/*Printing the countdown in the middle of the LCD screen*/
			break;
		case 150:
			LCD_moveCursor(2, 10);
			LCD_displayCharacter('2');
			/*Printing the countdown in the middle of the LCD screen*/
			break;
		case 200:
			LCD_moveCursor(2, 10);
			LCD_displayCharacter('1');
			/*Printing the countdown in the middle of the LCD screen*/
			break;
		case 249:
			LCD_moveCursor(2, 10);
			LCD_displayString("                ");
			break;
		default: ;
			/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
			/*Left for future update for error handling*/
		}
		if (Interrupt_Flag == TRUE) {
			Interrupt_Flag=FALSE;
			Return_to_Car_Mode_flag =TRUE;
			return;
		}

	}
}

void Y_Delay() {
	/*Function for displaying a countdown in the yellow led operation period together with the mode currently active*/
	for (uint8 i = 0; i < NB_OF_DELAY_LOOP_REPETITON; i++) {
		_delay_ms(NB_OF_MILLISECONDS_FOR_DELAY);
		if (Interrupt_Flag == TRUE) {
			Interrupt_Flag = FALSE;
			Return_to_Car_Mode_flag = TRUE;
			break;
		}
	}
}


void PedestrianMode(void){
	Interrupt_Flag = LOGIC_LOW;
	if (Led_Check(LED_RED) == LED_ON) {
		RoutineRED();
		} else if (Led_Check(LED_GREEN) == LED_ON) {
		RoutineGreen();
		} else {
		RoutineYellow();
	}
	Ext_Int1_SetFlag();
	Interrupt_Flag = TRUE;
}

void Pedestrian_CountDown() {
	/*Function for displaying a countdown in the pedestrian mode*/
	LCD_moveCursor(2, 10);
	LCD_displayCharacter('5');
	_delay_ms(1000);
	LCD_moveCursor(2, 10);
	LCD_displayCharacter('4');
	_delay_ms(1000);
	LCD_moveCursor(2, 10);
	LCD_displayCharacter('3');
	_delay_ms(1000);
	LCD_moveCursor(2, 10);
	LCD_displayCharacter('2');
	_delay_ms(1000);
	LCD_moveCursor(2, 10);
	LCD_displayCharacter('1');
	_delay_ms(1000);
}

void Pedestrian_Routine() {
	LED_on(LED_BLUE);
	LED_on(LED_RED);
	LCD_clearScreen();
	/*LCD Command(s) for the correct display*/
	LCD_moveCursor(1,6);
	LCD_displayString("PEDESTRIAN");
	Pedestrian_CountDown();
	/*LCD Command(s) for the correct display*/
	LCD_clearScreen();
	Led_All_Off();
}