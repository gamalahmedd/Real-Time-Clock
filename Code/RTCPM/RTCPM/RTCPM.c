#include <avr/io.h>
#include <avr/interrupt.h>
#include "BUTTON.h"
#include "MACROS.h"
#include "TIMER_TWO.h"
#include "USART.h"
#include "FOURTEEN_SEGMENT.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#define NOTPRESSED 0xFF
#define FORMAT_24 24
#define FORMAT_12 12

volatile unsigned char seconds = 0;
int main(void)
{
	unsigned char read_value;
	unsigned char minutes = 0;
	unsigned char hours = 0;
	unsigned char hours_show = hours;
	unsigned char clock_system[2] = "AM";
	unsigned char format = 12;
	DIO_vSetPortDirection('A', 0xFF);
	FOURTEEN_SEGMENT_vInit('B', 'C');
	BUTTON_vInit('D', 2);
	BUTTON_vInit('D', 3);
	BUTTON_vInit('D', 4);
	UART_vInit(9600);
	TIMER_TWO_vInitNormalMode(256, 1);
    while(1)
    {
       if(BUTTON_u8ReadStatus('D', 2) == 0)
	   {
		   _delay_ms(20);
		   if(BUTTON_u8ReadStatus('D', 2) == 0)
		   {
			   while (BUTTON_u8ReadStatus('D', 2) == 0);
			   UART_vSendData('1');
			   hours = UART_u8ReceiveData();
			   while(hours == 0xFF)
			   {
				   hours = UART_u8ReceiveData();
			   }				
			   minutes = UART_u8ReceiveData();
			   while(minutes == 0xFF)
			   {
				   minutes = UART_u8ReceiveData();
			   }	
			   seconds = UART_u8ReceiveData();
			   while(seconds == 0xFF)
			   {
				   seconds = UART_u8ReceiveData();
			   }				   			    
		   }
	   }
	   else if(BUTTON_u8ReadStatus('D', 3) == 0)
	   {
		   _delay_ms(20);
		   if(BUTTON_u8ReadStatus('D', 3) == 0)
		   {
			   while(BUTTON_u8ReadStatus('D', 3) == 0);
			   format = FORMAT_24;
			   DIO_vsetPinDir('A', PIN6, INPUT);
			   DIO_vsetPinDir('A', PIN7, INPUT);
		   }
	   }
	   else if(BUTTON_u8ReadStatus('D', 4) == 0)
	   {
		   _delay_ms(20);
		   if(BUTTON_u8ReadStatus('D', 4) == 0)
		   {
			   while(BUTTON_u8ReadStatus('D', 4) == 0);
			   format = FORMAT_12;
			   DIO_vsetPinDir('A', PIN6, OUTPUT);
			   DIO_vsetPinDir('A', PIN7, OUTPUT);
		   }
	   }	
	   else
	   {
		   UART_vSendData('0');
		   CLR_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (hours_show / 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   CLR_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (hours_show % 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   CLR_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (minutes / 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   CLR_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (minutes % 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   CLR_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (seconds / 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   CLR_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', (seconds % 10));
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   CLR_BIT(PORTA, 6);
		   SET_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', clock_system[0]);
		   _delay_ms(5);
		   SET_BIT(PORTA, 0);
		   SET_BIT(PORTA, 1);
		   SET_BIT(PORTA, 2);
		   SET_BIT(PORTA, 3);
		   SET_BIT(PORTA, 4);
		   SET_BIT(PORTA, 5);
		   SET_BIT(PORTA, 6);
		   CLR_BIT(PORTA, 7);
		   FOURTEEN_SEGMENT_vWrite('B', 'C', clock_system[1]);
		   _delay_ms(5);
		   if(seconds >= 60)
		   {
			   minutes++;
			   seconds = 0;
		   }		
		   if(minutes >= 60)
		   {
			   hours++;
			   minutes = 0;
			   seconds = 0;
		   }
		   if(format == FORMAT_12)
		   {
			   if(hours >= 24)
			   {
				   hours = 0;
				   minutes = 0;
				   seconds = 0;
			   }
			   if(hours == 0)
			   {
				   hours_show = 12;
				   clock_system[0] = 'A';
				   clock_system[1] = 'M';
			   }
			   else if(hours == 12)
			   {
				   hours_show = 12;
				   clock_system[0] = 'P';
				   clock_system[1] = 'M';
			   }				   
			   else if(hours > 0 && hours < 12)
			   {
				   hours_show = hours;
				   clock_system[0] = 'A';
				   clock_system[1] = 'M';
			   }
			   else
			   {
				   hours_show = hours - 12;
				   clock_system[0] = 'P';
				   clock_system[1] = 'M';
			   }
		   }	
		   else
		   {
			   if(hours >= 24)
			   {
				   hours = 0;
				   minutes = 0;
				   seconds = 0;
			   }	
			   hours_show = hours;			   
		   }		   
	   }		   	   
    }
}


ISR(TIMER2_OVF_vect)
{
	seconds++;	
}
