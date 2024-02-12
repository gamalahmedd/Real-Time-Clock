#ifndef BUTTON_H_
#define BUTTON_H_
/*
	Function Name        : BUTTON_vInit
	Function Returns     : void
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Set the direction of the given pin 0 = input to initialize for button
*/
void BUTTON_vInit(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : BUTTON_u8ReadStatus
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Read the value of the given pin to check if the switch is turned on or off
*/
unsigned char BUTTON_u8ReadStatus(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : BUTTON_vEnableInternalPullUp
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Enable the internal pull up for the given pin
*/
void BUTTON_vEnableInternalPullUp(unsigned char portname, unsigned char pinnumber);
/*
	Function Name        : BUTTON_vDisableInternalPullUp
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portname,unsigned char pinnumber
	Function Description : Disable the internal pull up for the given pin
*/
void BUTTON_vDisableInternalPullUp(unsigned char portname, unsigned char pinnumber);
#endif