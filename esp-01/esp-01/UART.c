/*
 * UART.c
 *
 * Created: 8/8/2020 9:14:39 PM
 *  Author: Ahmed EL-Tawab
 */ 
#include "UART.h"
void UART_INT()
{
	UBRRL=8;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
void UART_SEND_BYTE(unsigned char DATA)
{
	while(get_bit_(UCSRA,UDRE)==0);
	UDR=DATA;
}
unsigned char UART_RECEIVE_BYTE(){
	while(get_bit_(UCSRA,RXC)==0);
	return UDR;
}
void UART_SEND_STRING(char *STR)
{
	while(*STR!='\0')
	{
		UART_SEND_BYTE(*STR);
		STR++;
	}
}
void UART_RECEIVE(char *STR){
	unsigned char i=0;
	STR[i]=UART_RECEIVE_BYTE();
	while(STR[i] != '\n')
	{
		i++;
		STR[i]=UART_RECEIVE_BYTE();
	}
	i++;
	STR[i]='\0';
}