/*
 * L298_program.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Lenovo
 */

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "L298_interface.h"
#include "L298_config.h"

void L298_voidSetMotorsDirection(u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	case L298_Forward:
		DIO_voidSetPinValue(L298_Port , L298_PIN1 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN2 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN3 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN4 , DIO_u8LOW);
		break;
	case L298_Backward:
		DIO_voidSetPinValue(L298_Port , L298_PIN1 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN2 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN3 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN4 , DIO_u8HIGH);
		break;
	case L298_Stop:
		DIO_voidSetPinValue(L298_Port , L298_PIN1 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN2 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN3 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN4 , DIO_u8LOW);
		break;
	case L298_TurnLeft:
		DIO_voidSetPinValue(L298_Port , L298_PIN1 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN2 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN3 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN4 , DIO_u8HIGH);
		break;
	case L298_TurnRight:
		DIO_voidSetPinValue(L298_Port , L298_PIN1 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN2 , DIO_u8LOW);
		DIO_voidSetPinValue(L298_Port , L298_PIN3 , DIO_u8HIGH);
		DIO_voidSetPinValue(L298_Port , L298_PIN4 , DIO_u8LOW);
		break;
	}
}
