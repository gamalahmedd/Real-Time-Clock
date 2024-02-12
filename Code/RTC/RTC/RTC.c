#include <avr/io.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "SEV_SEGMENT.h"
#include "KEYPAD.h"
#include "TIMER_TWO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

volatile unsigned char seconds = 0;
int main(void)
{
	unsigned char first_digit = 0;
	unsigned char second_digit = 0;
	unsigned char hours = 0;
	unsigned char minutes = 0;
	unsigned char read_value = NOTPRESSED;
	//Initialize All Modules
    LCD_vInit();
	SEV_SEGMENT_vInit('B');
	SET_BIT(DDRC, PIN0);
	SET_BIT(DDRC, PIN1);
	SET_BIT(DDRC, PIN2);
	SET_BIT(DDRC, PIN3);
	SET_BIT(DDRC, PIN4);
	SET_BIT(DDRC, PIN5);
	KEYPAD_vInit('D');
	TIMER_TWO_vInitNormalMode(256, 1);
	LCD_vSendString("To set clock");
	LCD_vMoveCursor(2, 1);
	LCD_vSendString("Please press 1");
	while(1)
	{
		read_value = KEYPAD_u8Read('D');
		if(read_value != NOTPRESSED)
		{
			if(read_value == '1')
			{
				LCD_vClearScreen();
				LCD_vSendString("Hours: --");
				LCD_vMoveCursor(1, 8);
				do 
				{
					first_digit = KEYPAD_u8Read('D');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('D');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				hours = (10 * (first_digit - 48)) + (second_digit - 48);
				LCD_vClearScreen();
				LCD_vSendString("Minutes: --");
				LCD_vMoveCursor(1, 10);
				do
				{
					first_digit = KEYPAD_u8Read('D');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('D');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				minutes = (10 * (first_digit - 48)) + (second_digit - 48);
				LCD_vClearScreen();
				LCD_vSendString("Seconds: --");
				LCD_vMoveCursor(1, 10);
				do
				{
					first_digit = KEYPAD_u8Read('D');
				} while (first_digit == NOTPRESSED);
				LCD_vSendChar(first_digit);
				do
				{
					second_digit = KEYPAD_u8Read('D');
				} while (second_digit == NOTPRESSED);
				LCD_vSendChar(second_digit);
				seconds = (10 * (first_digit - 48)) + (second_digit - 48);
			}
			else
			{
				LCD_vClearScreen();
				LCD_vSendString("Wrong Choice!");
				_delay_ms(500);
				LCD_vClearScreen();
				LCD_vSendString("To set clock");
				LCD_vMoveCursor(2, 1);
				LCD_vSendString("Please press 1");
			}
		}	
		else
		{
			CLR_BIT(PORTC, PIN0);
			SET_BIT(PORTC, PIN1);
			SET_BIT(PORTC, PIN2);
			SET_BIT(PORTC, PIN3);
			SET_BIT(PORTC, PIN4);
			SET_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (hours / 10));
			_delay_ms(5);
			SET_BIT(PORTC, PIN0);
			CLR_BIT(PORTC, PIN1);
			SET_BIT(PORTC, PIN2);
			SET_BIT(PORTC, PIN3);
			SET_BIT(PORTC, PIN4);
			SET_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (hours % 10));
			_delay_ms(5);
			SET_BIT(PORTC, PIN0);
			SET_BIT(PORTC, PIN1);
			CLR_BIT(PORTC, PIN2);
			SET_BIT(PORTC, PIN3);
			SET_BIT(PORTC, PIN4);
			SET_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (minutes / 10));
			_delay_ms(5);
			SET_BIT(PORTC, PIN0);
			SET_BIT(PORTC, PIN1);
			SET_BIT(PORTC, PIN2);
			CLR_BIT(PORTC, PIN3);
			SET_BIT(PORTC, PIN4);
			SET_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (minutes % 10));
			_delay_ms(5);
			SET_BIT(PORTC, PIN0);
			SET_BIT(PORTC, PIN1);
			SET_BIT(PORTC, PIN2);
			SET_BIT(PORTC, PIN3);
			CLR_BIT(PORTC, PIN4);
			SET_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (seconds / 10));
			_delay_ms(5);
			SET_BIT(PORTC, PIN0);
			SET_BIT(PORTC, PIN1);
			SET_BIT(PORTC, PIN2);
			SET_BIT(PORTC, PIN3);
			SET_BIT(PORTC, PIN4);
			CLR_BIT(PORTC, PIN5);
			SEV_SEGMENT_vWrite('B', (seconds % 10));
			_delay_ms(5);
			if(seconds == 60)
			{
				minutes++;
				seconds = 0;
			}
			if(minutes == 60)
			{
				hours++;
				minutes = 0;
				seconds = 0;
			}
			if(hours == 24)
			{
				hours = 0;
				minutes = 0;
				seconds = 0;
			}
		}
	}
}

ISR(TIMER2_OVF_vect)
{
	seconds++;
}