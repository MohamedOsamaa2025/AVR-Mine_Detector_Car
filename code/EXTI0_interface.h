/*
 * interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: yosef
 */

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

void EXTI0_voidInit(void);
void EXTI0_voidSenseControl(u8 Copy_u8Sense);

void EXTIO_voidSetCallBack(void (*Copy_pvCallBack)(void));                      //pointer to function as an arg. for void setcallback


#define   LOW_LEVEL            1
#define   ANY_CHANGE           2
#define   FALLING_EDGE         3
#define   RISING_EDGE          4




#endif /* EXTI0_INTERFACE_H_ */
