#include "DIO.h"

void BUTTON_vInit(unsigned char portname, unsigned char pinnumber)
{
	DIO_vsetPinDir(portname, pinnumber, 0);
}

unsigned char BUTTON_u8ReadStatus(unsigned char portname, unsigned char pinnumber)
{
	unsigned char return_value = 0;
	return_value = DIO_u8ReadPin(portname, pinnumber);
	return return_value;
}

void BUTTON_vEnableInternalPullUp(unsigned char portname, unsigned char pinnumber)
{
	DIO_vConnectInternalPullUp(portname,pinnumber, 1);
}

void BUTTON_vDisableInternalPullUp(unsigned char portname, unsigned char pinnumber)
{
	DIO_vConnectInternalPullUp(portname,pinnumber, 0);
}