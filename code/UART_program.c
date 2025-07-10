/*
 * UART_program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"

void UART_voidInit(void)
{
	u8 Local_UCSRC=0b10000110;
	CLR_BIT(UCSRA,1); /*no double speed*/
	CLR_BIT(UCSRA,0);	/*set if master of slaves mode to be master*/
	/*select character size (8 bits)*/
	CLR_BIT(UCSRB,2);
	SET_BIT(Local_UCSRC,2);
	SET_BIT(Local_UCSRC,1);
	/*register select (UCSRC)*/
	SET_BIT(Local_UCSRC,7);
	/*Asynchronous mode*/
	CLR_BIT(Local_UCSRC,6);
	/*no parity*/
	CLR_BIT(Local_UCSRC,5);
	CLR_BIT(Local_UCSRC,4);
	/*stop bit select (1 bit)*/
	CLR_BIT(Local_UCSRC,3);
	UCSRC=Local_UCSRC; /*assign the value to the register (must all bits in same time)*/
	UBRRL=51; /*set baud rate to 9600*/
	SET_BIT(UCSRB,4);  /*enable reciever*/
	SET_BIT(UCSRB,3);  /*enable transmitter*/
}


void UART_voidSendData(u8 Copy_u8Data)
{ 		/*wait until register be empty*/
	while((GET_BIT(UCSRA,5))!=1)
	{
		asm("NOP");
	}
	UDR=Copy_u8Data;
}


u8 UART_u8ReceiveData(void)
{
		/*wait until recieve complete*/
	while((GET_BIT(UCSRA,7))!=1)
	{
		asm("NOP");
	}
	return UDR;  /*read the data*/
}
