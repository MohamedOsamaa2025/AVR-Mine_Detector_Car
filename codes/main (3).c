/*
 * Mine_Detector_main.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lenovo
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "L298_interface.h"
#include "UART_interface.h"


void motion (void);
void detection(void);
u8 Data;	/*for receiving*/
u8 flag=0;
int main(void)
{

	/*L298 port*/
	DIO_VoidSetPortDirection(DIO_u8PORTA,0b11111111);
	/*Rx input*/
	DIO_voidSetPinDirection(DIO_u8PORTD,0,DIO_u8INPUT);
//	/*tx output*/
//	DIO_voidSetPinDirection(DIO_u8PORTD,1,DIO_u8OUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORTD,7,DIO_u8INPUT);        //input from buzzer mine
	DIO_voidSetPinValue(DIO_u8PORTD,7,DIO_u8HIGH);		//pull up

	UART_voidInit();

	while(1)
	{
//		detection();
		if (DIO_u8GetPinValue(DIO_u8PORTD,7)==0)
		{
			DIO_voidSetPinValue(DIO_u8PORTA,7,DIO_u8HIGH);

		}
		if (DIO_u8GetPinValue(DIO_u8PORTD,7)==1)
		{
			DIO_voidSetPinValue(DIO_u8PORTA,7,DIO_u8LOW);

		}


	}
}
void detection(void)
{
	if (DIO_u8GetPinValue(DIO_u8PORTD,7)==0)
	{
		flag=1;
		/*move backword to exit loop*/
//						UART_voidSendData('T');
		DIO_voidSetPinValue(DIO_u8PORTA,7,DIO_u8HIGH);
//
//		while(Data!='B')
//		{
//			L298_voidSetMotorsDirection(L298_Stop);
//			Data=UART_u8ReceiveData();
//		}
		if(Data=='B')
		{
			L298_voidSetMotorsDirection(L298_Backward);

		}


	}
	else
	{
		DIO_voidSetPinValue(DIO_u8PORTA,7,DIO_u8LOW);
		flag=0;
		motion();

}

}

void motion (void)
{



	Data=UART_u8ReceiveData();
	switch(Data)
	{
	case 'F':
		L298_voidSetMotorsDirection(L298_Forward);
		break;
	case 'B':
		L298_voidSetMotorsDirection(L298_Backward);
		break;
	case 'L':
		L298_voidSetMotorsDirection(L298_TurnLeft);
		break;
	case 'R':
		L298_voidSetMotorsDirection(L298_TurnRight);
		break;
	case 'S':
		L298_voidSetMotorsDirection(L298_Stop);
		break;
	}

}
