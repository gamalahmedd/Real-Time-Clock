#include "DIO.h"
#include "MACROS.h"
#define COM_CATHODE

void SEV_SEGMENT_vInit(unsigned char portname)
{
	DIO_vSetPortDirection(portname, 0xFF);
}

void SEV_SEGMENT_vWrite(unsigned char portname, unsigned char number, unsigned char *type)
{
	#if defined COM_CATHODE
	unsigned char arr[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f};
	DIO_vWritePort(portname, arr[number]);
	#elif defined COM_ANODE
	unsigned char arr[10] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d, ~0x7d, ~0x47, ~0x7f, ~0x6f};
	DIO_vWritePort(portname, arr[number]);
	#endif
}

void SEV_SEGMENT_vInitBCD(unsigned char portname)
{
	DIO_vsetPinDir(portname, PIN0, OUTPUT);
	DIO_vsetPinDir(portname, PIN1, OUTPUT);
	DIO_vsetPinDir(portname, PIN2, OUTPUT);
	DIO_vsetPinDir(portname, PIN3, OUTPUT);
}

void SEV_SEGMENT_vWriteBCD(unsigned char portname, unsigned char number)
{
	DIO_vWriteLowNibble(portname, number);
}