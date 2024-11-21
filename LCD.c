/*
 * LCD.c
 *
 * Created: 10/7/2024 7:40:28 PM
 *  Author: GHADA_ABODA
 */ 
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void LCD_Initial(void)
{
	_delay_ms(2);
	#if defined eight_bits_mode
	DIO_SetPinDirection('A',0,1);
	DIO_SetPinDirection('A',1,1);
	DIO_SetPinDirection('A',2,1);
    DIO_SetPinDirection('A',3,1);
	DIO_SetPinDirection('A',4,1);
	DIO_SetPinDirection('A',5,1);
	DIO_SetPinDirection('A',6,1);
	DIO_SetPinDirection('A',7,1);
	DIO_SetPinDirection('B',EN,1);
	DIO_SetPinDirection('B',RW,1);
	DIO_SetPinDirection('B',RS,1);
	DIO_WritePin('B',RW,0);
	LCD_Send_Cmd(EIGHT_BITS);
	LCD_Send_Cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_Send_Cmd(CLR_SCREEN );
	_delay_ms(1);
	LCD_Send_Cmd(ENTRY_MODE);
	_delay_ms(1);
	LCD_Send_Cmd(RETURN_MODE);
	_delay_ms(1);
	#elif defined four_bits_mode
	DIO_SetPinDirection('A',4,1);
	DIO_SetPinDirection('A',5,1);
	DIO_SetPinDirection('A',6,1);
	DIO_SetPinDirection('A',7,1);
	DIO_SetPinDirection('B',EN,1);
	DIO_SetPinDirection('B',RW,1);
	DIO_SetPinDirection('B',RS,1);
	DIO_WritePin('B',RW,0);
	
LCD_Send_Cmd(FOUR_BITS);
_delay_ms(1);
LCD_Send_Cmd(CURSOR_ON_DISPLAY_ON);
_delay_ms(1);
LCD_Send_Cmd(CLR_SCREEN);
_delay_ms(1);
LCD_Send_Cmd(ENTRY_MODE);
_delay_ms(1);
LCD_Send_Cmd(RETURN_MODE);
_delay_ms(1);
#endif
	
}
static void send_falling_edg(void)
{
	DIO_WritePin('B',EN,1);
	_delay_ms(2);
	DIO_WritePin('B',EN,0);
	_delay_ms(2);
}
void LCD_Send_Cmd( char cmd)
{
	#if  defined eight_bits_mode
	DIO_WritePort('A',cmd);
	DIO_WritePin('B',RS,0);
	send_falling_edg();
	#elif defined four_bits_mode
   DIO_Write_High_Nibbl('A',cmd>>4);
   DIO_WritePin('B',RS,0);
   send_falling_edg(); 
  #endif
  _delay_ms(1);
}
void LCD_Send_data(unsigned char data)
{
	#if defined eight_bits_mode
	DIO_WritePort('A',data);
	DIO_WritePin('B',RS,1);
	send_falling_edg();
	#elif defined four_bits_mode
	DIO_Write_High_Nibbl('A',data>>4);
	DIO_WritePin('B',RS,1);
	send_falling_edg();
	#endif 
	_delay_ms (1);
}
void LCD_Send_String(unsigned char *data)
{
	while (*data!='\0')
{
	LCD_Send_data(*data);
	data++;
	
}
	
}	
void LCD_CLR_Screen()
{
	LCD_Send_Cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_Move_Cursor(unsigned char row, unsigned char column)
{
	unsigned char data;
	if (row > 2 || row < 1 || column > 16 || column < 1)
	{
		data = 0x80;
	}
	else if (row == 1)
	{
		data = 0x80 + column - 1;
	}
	else if (row == 2)
	{
		data = 0xC0 + column - 1;
	}
	LCD_Send_Cmd(data);
	_delay_ms(0.1);

} 
unsigned char LCD_Get_Cursor_Position()
{
    // Your specific implementation here
    // Typically, this could read from a register or maintain a variable within the LCD library
    unsigned char position = 0; // Placeholder, replace with actual logic
    return position;
}
   void LCD_Send_Integer(int  num)
    {
	  char buffer[16];
	  itoa(num, buffer, 10); // Convert integer to string
	  LCD_Send_String(buffer);
  }