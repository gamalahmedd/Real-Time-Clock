#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "USART.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	char read;
	unsigned char hours = 0;
	unsigned char minutes = 0;
	unsigned char seconds = 0;
	unsigned char first_digit = 0, second_digit = 0;
	unsigned char flag = 1;
    LCD_vInit();
	KEYPAD_vInit('C');
	UART_vInit(9600);
	LCD_vSendString("To set clock");
	LCD_vMoveCursor(2, 1);
	LCD_vSendString("Please Push Reset");
	while(1)
	{
		read = UART_u8ReceiveData();
		if(read == '1')
		{
			flag = 1;
			while(flag == 1)
			{
				LCD_vClearScreen();
				LCD_vSendString("Hours: --");
				LCD_vMoveCursor(1, 8);
				hours = NOTPRESSED;
				UART_vSendData(hours);
				do
				{
					first_digit = KEYPAD_u8Read('C');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('C');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				hours = ((first_digit- 48) * 10) + (second_digit - 48);
				if(hours >= 24)
				{
					LCD_vClearScreen();
					LCD_vSendString("Wrong Choice!");
					LCD_vMoveCursor(2, 1);
					LCD_vSendString("hours must be<24");
					_delay_ms(1000);
				}
				else
				{
					flag = 0;
				}
			}
			UART_vSendData(hours);
			flag = 1;
			while(flag == 1)
			{
				LCD_vClearScreen();
				LCD_vSendString("Minutes: --");
				LCD_vMoveCursor(1, 10);
				minutes = NOTPRESSED;
				UART_vSendData(minutes);
				do
				{
					first_digit = KEYPAD_u8Read('C');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('C');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				minutes = ((first_digit- 48) * 10) + (second_digit - 48);
				if(minutes >= 60)
				{
					LCD_vClearScreen();
					LCD_vSendString("Wrong Choice!");
					LCD_vMoveCursor(2, 1);
					LCD_vSendString("minutes must be<60");
					_delay_ms(1000);
				}
				else
				{
					flag = 0;
				}
			}
			UART_vSendData(minutes);
			flag = 1;
			while(flag == 1)
			{
				LCD_vClearScreen();
				LCD_vSendString("Seconds: --");
				LCD_vMoveCursor(1, 10);
				seconds = NOTPRESSED;
				UART_vSendData(seconds);
				do
				{
					first_digit = KEYPAD_u8Read('C');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('C');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				seconds = ((first_digit- 48) * 10) + (second_digit - 48);
				if(seconds >= 60)
				{
					LCD_vClearScreen();
					LCD_vSendString("Wrong Choice!");
					LCD_vMoveCursor(2, 1);
					LCD_vSendString("seconds must be<60");
					_delay_ms(1000);
				}
				else
				{
					flag = 0;
				}
			}
			UART_vSendData(seconds);
			LCD_vClearScreen();
			LCD_vSendString("To set clock");
			LCD_vMoveCursor(2, 1);
			LCD_vSendString("Please Push Reset");
		}
	}
}

