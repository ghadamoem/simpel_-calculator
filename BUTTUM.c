/*
 * BUTTUM.c
 *
 * Created: 9/25/2024 10:24:05 PM
 *  Author: User
 */ 
#include "DIO.h"
#include <avr/io.h>
void BUSH_BUTT_Initil(unsigned char port_name,unsigned char pin)
{
	DIO_SetPinDirection(port_name,pin,1);
}
char BUSH_BUTT_READ(unsigned char port_name,unsigned char pin)
{
	return  DIO_u8Read(port_name,pin);
}