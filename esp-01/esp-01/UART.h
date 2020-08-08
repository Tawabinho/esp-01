/*
 * UART.h
 *
 * Created: 8/8/2020 9:14:54 PM
 *  Author: Ahmed EL-Tawab
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#include "bit_math_.h"
void UART_INT();
void UART_SEND_BYTE(unsigned char DATA);
unsigned char UART_RECEIVE_BYTE();
void UART_SEND_STRING(char *STR);
void UART_RECEIVE(char *STR);
#endif /* UART_H_ */