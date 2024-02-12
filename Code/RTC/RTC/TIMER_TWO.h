#ifndef TIMER_TWO_H_
#define TIMER_TWO_H_
/*
	Function Name        : TIMER_TWO_vInitNormalMode
	Function Returns     : void
	Function Arguments   : unsigned char timer_count, unsigned char interrupt_enable
	Function Description : Initialize Timer2 with normal mode
*/
void TIMER_TWO_vInitNormalMode(unsigned char timer_count, unsigned char interrupt_enable);
/*
	Function Name        : TIMER_TWO_vInitCTCMode
	Function Returns     : void
	Function Arguments   : unsigned char timer_count, unsigned char interrupt_enable
	Function Description : Initialize Timer2 with ctc mode
*/
void TIMER_TWO_vInitCTCMode(unsigned char timer_count, unsigned char interrupt_enable);
/*
	Function Name        : TIMER_TWO_vGenerateNonPWMSignal
	Function Returns     : void
	Function Arguments   : unsigned char timer_count
	Function Description : Generate Non-PWM Signal using Timer2 with ctc mode
*/
void TIMER_TWO_vGenerateNonPWMSignal(unsigned char timer_count);
/*
	Function Name        : TIMER_TWO_vGenerateFastPWMSignal
	Function Returns     : void
	Function Arguments   : unsigned char timer_count
	Function Description : Generate PWM Signal using Timer2 with Fast PWM mode
*/
void TIMER_TWO_vGenerateFastPWMSignal(unsigned char timer_count);
/*
	Function Name        : TIMER_TWO_vGeneratePhaseCorrectPWMSignal
	Function Returns     : void
	Function Arguments   : unsigned char timer_count
	Function Description : Generate PWM Signal using Timer2 with Phase-Correct PWM mode
*/
void TIMER_TWO_vGeneratePhaseCorrectPWMSignal(unsigned char timer_count);
#endif