/*
 * UART_register.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Lenovo
 */

#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_


#define UDR *((volatile u8*)(0x2c))
#define UCSRA *((volatile u8*)(0x2b))
#define UCSRB *((volatile u8*)(0x2a))
#define UCSRC *((volatile u8*)(0x40))
#define UBRRL *((volatile u8*)(0x29))
#define UBRRH *((volatile u8*)(0x40))


#endif /* UART_REGISTER_H_ */
