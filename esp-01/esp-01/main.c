/*
 * esp-01.c
 *
 * Created: 8/8/2020 9:09:31 PM
 * Author : Ahmed EL-Tawab
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include "bit_math_.h"
#include "UART.h"
#include "lcd_.h"
#include "lcd_config.h"
#include <util/delay.h>
int main(void)
{
	char RECEIVE[100];
    UART_INT();
	_delay_ms(1);
	lcd_int_();
	_delay_ms(1);
	lcd_command_(0x80);
	lcd_string_("hello");
	_delay_ms(1000);
	lcd_clear();
	lcd_command_(0x80);
	UART_SEND_STRING("AT");
	_delay_ms(1);
	UART_RECEIVE(RECEIVE);
	_delay_ms(1);
	lcd_string_(RECEIVE);
    while (1) 
    {
    }
}

