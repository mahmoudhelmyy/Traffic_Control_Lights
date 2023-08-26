/*
 * AVR_LCD.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
 */
#include "AVR_LCD.h"
#include <stdlib.h>

/*
  Initialize the LCD:
  1. Setup the LCD pins directions by use the DIO driver.
  2. Setup the LCD Data Mode 4 bits OR 8 bits.
 */
void LCD_init(void){
	/*4Bit Mode*/
	DIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	_delay_ms(20);
	
	#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	DIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,PIN_OUTPUT);
	DIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,PIN_OUTPUT);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
	LCD_sendCommand(LCD_CURSOR_OFF);
	_delay_ms(10);
	#elif(LCD_DATA_BITS_MODE == 8)
	DIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	#endif
	
	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
Send the required command to the screen
*/
void LCD_sendCommand(uint8 command){
	DIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);  	/*Select command mode 0*/
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);    /* Enable LCD E=1 */
	_delay_ms(1);
	#if(LCD_DATA_BITS_MODE == 4)							
    /*This is the mode chosen as per hardware configuration of the kit used*/
	/*Sending the high nibble*/
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));
	_delay_ms(1);
	/*For the LCD to work in 4 bit mode the first high nibble must be sent (E=1),
	and then enable pin is set to low (E=0), then enabling the pin again (E=1) then the low nibble is sent*/
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_ms(1);
	/*Sending the low nibble*/
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);    /*Data transfer is done, disable (E=0)*/
	_delay_ms(1);

	#elif(LCD_DATA_BITS_MODE == 8)
	DIO_writePort(LCD_DATA_PORT_ID,command);
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	#endif
}

void LCD_displayCharacter(uint8 data){
	DIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);  /*Select data mode 1*/
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);    /* Enable LCD E=1 */
	_delay_ms(1);

	#if(LCD_DATA_BITS_MODE == 4)                            
	/*This is the mode chosen as per hardware configuration of the kit used*/
	/*Sending the high nibble*/
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));
	_delay_ms(1);
	
	/*For the LCD to work in 4 bit mode the first high nibble must be sent (E=1),
	and then enable pin is set to low (E=0), then enabling the pin again (E=1) then the low nibble is sent*/
	
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);         /* Disable LCD E=0*/
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);        /* Enable LCD E=1 */
	_delay_ms(1);
	/*Sending the low nibble*/
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	DIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);    /*Data transfer is done, disable (E=0)*/
	_delay_ms(1);

	#elif(LCD_DATA_BITS_MODE == 8)
	DIO_writePin(LCD_DATA_PORT_ID,data);
	_delay_ms(1);
	DIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_ms(1);
	#endif
}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while (Str[i] !='\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address = 0;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x14;
		break;
	case 3:
		lcd_memory_address=col+0x54;
		break;
	default: ;
		/*MISRA C 2012 - 16.4 default must be present in every switch statement*/
		/*Left for future update for error handling*/
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col);				/* go to to the required LCD position */
	LCD_displayString(Str);					/* display the string */
}

void LCD_intgerToString(int data)
{
	char buff[16];						/* String to hold the ascii result */
	itoa(data,buff,10);					/* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff);			 /* Display the string */
}