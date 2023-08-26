/*
 * Interrupts_atmega32.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
 */

#include "atmega32_Interrupts.h"


 /*Enable for All Maskable Interrupts*/
void Global_Interrupt_Init(){                      
    /* Enable global interrupts by setting the appropriate bit in the status register */
    SREG |= (uint8)GLOBAL_INTERRUPT_ENABLE_BIT;
}

 /*Enable for INT0 External Interrupt*/
void Ext_Int0_Enable(uint8 Mode){
	DIO_setupPinDirection(PORTD, PIN2_ID, PIN_INPUT);
	GICR|=INT0_ENABLE;
	MCUCR|=Mode;
}

 /*Disable for INT0 External Interrupt*/
void Ext_Int0_Disable(){
	GICR&=~INT0_ENABLE;
}

 /*Enable for INT1 External Interrupt*/
void Ext_Int1_Enable(){
	DIO_setupPinDirection(PORTD, PIN3_ID, PIN_INPUT);
	GICR|=INT1_ENABLE;
	MCUCR|=0x08;
}

void Ext_Int1_SetFlag(){
	SET_BIT(GIFR,INT1F);
}

 /*Disable for INT1 External Interrupt*/
void Ext_Int1_Disable(){
	GICR&=~INT1_ENABLE;
}

 /*Enable for INT2 External Interrupt*/
void Ext_Int2_Enable(uint8 Mode){
	DIO_setupPinDirection(PORTB, PIN2_ID, PIN_INPUT);
	GICR|=INT2_ENABLE;
	MCUCR|=Mode;
}
 /*Disable for INT0 External Interrupt*/
void Ext_Int2_Disable(){
	GICR&=~INT2_ENABLE;
}

ISR (INT1_Vector)
{
	CallbacktoPedestrianMode(Callback_ptr);
}