#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "L298_interface.h"
#include "UART_interface.h"

#include "EXTI0_interface.h"
#include "GIE_interface.h"


void motion (void);
void detection(void);

u8 Data;	/*for receiving*/

int main(void)
{

	/*L298 port*/
	DIO_VoidSetPortDirection(DIO_u8PORTA,0b10001111);
	/*Rx input*/
	DIO_voidSetPinDirection(DIO_u8PORTD,0,DIO_u8INPUT);

	DIO_voidSetPinDirection(DIO_u8PORTD,7,DIO_u8OUTPUT);

	DIO_voidSetPinDirection(DIO_u8PORTD,2,DIO_u8INPUT);  //input from buzzer (EXTI0)
	DIO_voidSetPinValue(DIO_u8PORTD,2,DIO_u8HIGH);		//pull up


	GIE_voidEnable();
	EXTI0_voidInit();
	UART_voidInit();
	L298_voidSetMotorsDirection(L298_Stop);

	while(1)
	{
		motion();

	}
}

void detection(void)
{
		L298_voidSetMotorsDirection(L298_Stop);
		DIO_voidSetPinValue(DIO_u8PORTD,7,DIO_u8HIGH);
		while(UART_u8ReceiveData()!='B')
		{
			asm("NOP");
		}
		L298_voidSetMotorsDirection(L298_Backward);

		DIO_voidSetPinValue(DIO_u8PORTD,7,DIO_u8LOW);
}

void motion (void)
{
	Data=UART_u8ReceiveData();
	switch(Data)
	{
	case 'B':
		L298_voidSetMotorsDirection(L298_Backward);
		break;
	case 'F':
		L298_voidSetMotorsDirection(L298_Forward);
		break;
	case 'R':
		L298_voidSetMotorsDirection(L298_TurnRight);
		break;
	case 'L':
		L298_voidSetMotorsDirection(L298_TurnLeft);
		break;
	case 'S':
		L298_voidSetMotorsDirection(L298_Stop);
		break;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	detection();
}
