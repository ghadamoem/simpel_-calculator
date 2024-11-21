/*
 * DIO.h
 *
 * Created: 10/19/2023 12:08:38 PM
 *  Author: Ghada_Moemn
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_SetPinDirection(unsigned char PORT,unsigned char PIN,unsigned char direction);
void  DIO_WritePin(unsigned char PORT ,unsigned char PIN,unsigned char valu );
void DIO_TogPin(unsigned char PORT,unsigned char PIN);
unsigned char DIO_u8Read(unsigned char PORT,unsigned char PIN);
void DIO_SetPortDirection(unsigned char PORT,unsigned char direction);

void DIO_WritePort(unsigned char PORT,unsigned char PortTValue);
unsigned char DIO_Read_Port(unsigned char PORT);
void DIO_TOG_PORT(unsigned char PORT);
void DIO_Connect_Pullup(unsigned char PORT,unsigned char PIN,unsigned char connect);
#endif /* DIO_H_ */