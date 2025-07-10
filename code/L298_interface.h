/*
 * L298_interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Lenovo
 */

#ifndef L298_INTERFACE_H_
#define L298_INTERFACE_H_

		/*motors direction*/
#define L298_Forward		0
#define L298_Backward		1
#define L298_Stop			2
#define L298_TurnLeft		3
#define L298_TurnRight		4


void L298_voidSetMotorsDirection(u8 Copy_u8Direction);


#endif /* L298_INTERFACE_H_ */
