/*
 * KEYPAD.c
 *
 * Created: 10/9/2024 1:52:38 AM
 *  Author: GHADA_MOMEN
 */ 
#include "KEYPAD.h"
#include "BUTTUM.h"
#include "DIO.h"
void KeyPad_Initial(void)
{

	DIO_SetPinDirection('D',0,1);
	DIO_SetPinDirection('D',1,1);
	DIO_SetPinDirection('D',2,1);
	DIO_SetPinDirection('D',3,1);
	DIO_SetPinDirection('D',4,0);
	DIO_SetPinDirection('D',5,0);
	DIO_SetPinDirection('D',6,0);
	DIO_SetPinDirection('D',7,0);
	DIO_Connect_Pullup('D',4,1);
	DIO_Connect_Pullup('D',5,1);
	DIO_Connect_Pullup('D',6,1);
	DIO_Connect_Pullup('D',7,1);
	
}
unsigned char KeyPad_Read(void)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
		char row,coloumn,x;
		char return_value= 0xff;
		for (row=0;row<4;row++)
		{
			DIO_WritePin('D',0,1);
			DIO_WritePin('D',1,1);
			DIO_WritePin('D',2,1);
			DIO_WritePin('D',3,1);
			DIO_WritePin('D',row,0);
			for (coloumn=0;coloumn<4;coloumn++)
			{
				x= DIO_u8Read('D',(coloumn+4));
				if(x==0)
				{
					return_value=arr[row][coloumn];
					break;
				}
			}
			if(x==0)
			{
				break;
			}
		}
		return return_value;		
}

