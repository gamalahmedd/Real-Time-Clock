#include <avr/io.h>
#include <avr/interrupt.h>
#include "MACROS.h"
#define EXTERNAL_CLK


void TIMER_TWO_vInitNormalMode(unsigned char timer_count, unsigned char interrupt_enable)
{
	if(interrupt_enable == 1)
	{
		//Select Timer Clock Source
		#if defined EXTERNAL_CLK
		SET_BIT(ASSR, AS2);
		#elif defined INTERNAL_CLK
		CLR_BIT(ASSR, AS2);
		#endif
		//Init timer2 with prescaler 128
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		//Set Normal Mode
		CLR_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		//Init TCNT2 with timer_count
		TCNT2 = 256 - timer_count;
		//Set Global Interrupt bit
		sei();
		//Enable Overflow Interrupt Mode
		SET_BIT(TIMSK, TOIE2);
	}
	else
	{
		//Select Timer Clock Source
		#if defined EXTERNAL_CLK
		SET_BIT(ASSR, AS2);
		#elif defined INTERNAL_CLK
		CLR_BIT(ASSR, AS2);
		#endif
		//Init timer2 with prescaler 128
		SET_BIT(TCCR2, CS20);
		CLR_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		//Set Normal Mode
		CLR_BIT(TCCR2, WGM20);
		CLR_BIT(TCCR2, WGM21);
		//Init TCNT2 with timer_count
		TCNT2 = 256 - timer_count;
	}
}


void TIMER_TWO_vInitCTCMode(unsigned char timer_count, unsigned char interrupt_enable)
{
	if(interrupt_enable == 1)
	{
		//Select Timer Clock Source
		#if defined EXTERNAL_CLK
		SET_BIT(ASSR, AS2);
		#elif defined INTERNAL_CLK
		CLR_BIT(ASSR, AS2);
		#endif
		//Init timer2 with prescaler 1024
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		//Set CTC Mode
		CLR_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		//Init TCNT2 with 0 value
		TCNT2 = 0;
		//Init OCR2 with timer_count
		OCR2 = timer_count;
		//Set Global Interrupt bit
		sei();
		//Enable Overflow Interrupt Mode
		SET_BIT(TIMSK, OCIE2);
	}
	else
	{
		//Select Timer Clock Source
		#if defined EXTERNAL_CLK
		SET_BIT(ASSR, AS2);
		#elif defined INTERNAL_CLK
		CLR_BIT(ASSR, AS2);
		#endif
		//Init timer2 with prescaler 1024
		SET_BIT(TCCR2, CS20);
		SET_BIT(TCCR2, CS21);
		SET_BIT(TCCR2, CS22);
		//Set CTC Mode
		CLR_BIT(TCCR2, WGM20);
		SET_BIT(TCCR2, WGM21);
		//Init TCNT2 with 0 value
		TCNT2 = 0;
		//Init OCR2 with timer_count
		OCR2 = timer_count;
	}
}

void TIMER_TWO_vGenerateNonPWMSignal(unsigned char timer_count)
{
	//To Set OC2 as output bit
	SET_BIT(DDRD, PIN7);
	//Init timer2 with prescaler 1024
	SET_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);
	//Set CTC Mode
	CLR_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);
	//Toggle OC2 On Compare Match
	SET_BIT(TCCR2, COM20);
	CLR_BIT(TCCR2, COM21);
	//Init TCNT2 with 0 value
	TCNT2 = 0;
	//Init OCR2 with timer_count
	OCR2 = timer_count;
}

void TIMER_TWO_vGenerateFastPWMSignal(unsigned char timer_count)
{
	//To Set OC2 as output bit
	SET_BIT(DDRD, PIN7);
	//Init timer2 with prescaler 1024
	SET_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);
	//Set Fast PWM Mode
	SET_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);
	//Non Inverting Mode
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	//Init TCNT2 with 0 value
	TCNT2 = 0;
	//Init OCR2 with timer_count
	OCR2 = timer_count;
}

void TIMER_TWO_vGeneratePhaseCorrectPWMSignal(unsigned char timer_count)
{
	//To Set OC2 as output bit
	SET_BIT(DDRD, PIN7);
	//Init timer2 with prescaler 1024
	SET_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);
	//Set Phase-Correct PWM Mode
	SET_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);
	//Inverting Mode
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
	//Init TCNT2 with 0 value
	TCNT2 = 0;
	//Init OCR2 with timer_count
	OCR2 = timer_count;
}