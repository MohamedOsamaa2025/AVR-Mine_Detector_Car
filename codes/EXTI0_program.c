/*
 * ext_program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: yosef
 */

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "DIO_interface.h"

#include  "EXTI0_config.h"
#include  "EXTI0_interface.h"
#include  "EXTI0_private.h"
#include  "EXTI0_register.h"

void (*EXTI0_CallBack)(void);
/*global ptr for receiving the address of the function ptr
 as a global variable to be seen by void __vector_1(void)*/

void EXTI0_voidInit(void)
{
	switch(SENSE)
	{
	case LOW_LEVEL :
					CLR_BIT(MCUCR ,0);
					CLR_BIT(MCUCR ,1);
					break;

	case ANY_CHANGE :
					SET_BIT(MCUCR ,0);
					CLR_BIT(MCUCR ,1);
					break;

	case FALLING_EDGE :
					CLR_BIT(MCUCR ,0);
					SET_BIT(MCUCR ,1);
					break;

	case RISING_EDGE :
					SET_BIT(MCUCR ,0);
					SET_BIT(MCUCR ,1);
					break;

	}

	SET_BIT(GICR,6);
}

void EXTI0_voidSenseControl(u8 Copy_u8Sense)
{
	switch(Copy_u8Sense)
		{
		case LOW_LEVEL :
						CLR_BIT(MCUCR ,0);
						CLR_BIT(MCUCR ,1);
						break;

		case ANY_CHANGE :
						SET_BIT(MCUCR ,0);
						CLR_BIT(MCUCR ,1);
						break;

		case FALLING_EDGE :
						CLR_BIT(MCUCR ,0);
						SET_BIT(MCUCR ,1);
						break;

		case RISING_EDGE :
						SET_BIT(MCUCR ,0);
						SET_BIT(MCUCR ,1);
						break;

		}
}

void EXTIO_voidSetCallBack(void (*Copy_pvCallBack)(void))
{
	EXTI0_CallBack = Copy_pvCallBack;
}


//void __vector_1(void) __attribute__((signal));
///*atribute for communicating compiler*/
//
//void __vector_1(void)
//{
//	EXTI0_CallBack();
//}
