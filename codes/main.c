/*
 * main.c
 *
 *  Created on: Dec 27, 2023
 *      Author: yosef
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "EXTI0_interface.h"
#include "GIE_interface.h"

void LED (void);


int main(void)
{

DIO_voidSetPinDirection(DIO_u8PORTD,2,DIO_u8INPUT);  //input from buzzer (EXTI0)
DIO_voidSetPinValue(DIO_u8PORTD,2,DIO_u8HIGH);		//pull up

DIO_voidSetPinDirection(DIO_u8PORTD,7,DIO_u8OUTPUT);


GIE_voidEnable();
EXTI0_voidInit();


while(1)
{

}
}


void LED (void)
{

		DIO_voidSetPinValue(DIO_u8PORTD,7,DIO_u8HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_u8PORTD,7,DIO_u8LOW);


}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	LED();
}
