#include "DIO.h"
#include "MACROS.h"
#define COM_CATHODE

void FOURTEEN_SEGMENT_vInit(unsigned char portname1, unsigned portname2)
{
	DIO_vWritePort(portname1, 0xFF);
	DIO_vWritePort(portname2, 0x3F);
}

void FOURTEEN_SEGMENT_vWrite(unsigned char portname1, unsigned portname2, unsigned char input_value)
{
	#if defined COM_CATHODE
	unsigned short arr[91] = {
		0x113F, 0x0106, 0x221B, 0x220F, 0x2226, 0x2429, 0x0223D, 0x0007, 0x0223F, 0x222F, [65] = 0x2237, 0x0A8F,
		0x0039, 0x088F, 0x2039, 0x2031, 0x023D, 0x02236, 0x0889, 0x001E, 0x2530, 0x0038, 0x0176, 0x0476, 0x003F,
		0x2233, 0x043F, 0x2633, 0x222D, 0x0881, 0x003E, 0x1130, 0x1436, 0x1540, 0x0940, 0x1109
		};
	DIO_vWritePort(portname1, arr[input_value]);
	DIO_vWritePort(portname2, (arr[input_value] >> 8));
	#elif defined COM_ANODE
	unsigned short arr[91] = {
		~0x113F, ~0x0106, ~0x221B, ~0x220F, ~0x2226, ~0x2429, ~0x0223D, ~0x0007, ~0x0223F, ~0x222F, [65] = ~0x2237, ~0x0A8F,
		~0x0039, ~0x088F, ~0x2039, ~0x2031, ~0x023D, ~0x02236, ~0x0889, ~0x001E, ~0x2530, ~0x0038, ~0x0176, ~0x0476, ~0x003F,
		~0x2233, ~0x043F, ~0x2633, ~0x222D, ~0x0881, ~0x003E, ~0x1130, ~0x1436, ~0x1540, ~0x0940, ~0x1109
	};
	DIO_vWritePort(portname1, arr[input_value]);
	DIO_vWritePort(portname2, (arr[input_value] >> 8));
	#endif
}