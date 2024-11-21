/*
 * DIO.c
 *
 * Created: 10/19/2023 12:08:18 PM
 *  Author: Ghada_Moemn
 */ 
#include <avr/io.h>
#include "std_macros.h"
#include "DIO.h"
void DIO_SetPinDirection(unsigned char PORT,unsigned char PIN,unsigned char direction)
{
	switch (PORT)
	{
		case 'A':
		case 'a':
		if(direction==1)
		{
			
			SET_BIT(DDRA, PIN)	;
		}
		else
		{
			CLR_BIT(DDRA, PIN);
		}
		break;
		case 'B':
		case 'b':
		if(direction==1)
		{
			SET_BIT(DDRB, PIN);
			
		}
		else
		{
			CLR_BIT(DDRB, PIN);
		}
		break;
		
		case 'C':
		case 'c':
		if(direction==1)
		{
			SET_BIT(DDRC, PIN)	;
			
		}
		else
		{
			CLR_BIT(DDRC, PIN);
		}
		break;
		
		case 'D':
		case'd':
		if(direction==1)
		{
			
		
		SET_BIT(DDRD, PIN);
		
	}
	else
	{
		CLR_BIT(DDRD, PIN);
	}
	break;
	default:
	break;
}
}


	
	void  DIO_WritePin(unsigned char PORT ,unsigned char PIN,unsigned char valu )
	{
	switch(PORT)
	{
		case 'A':
		case 'a':
		if(valu==1)
		
		{
			SET_BIT(PORTA,PIN);
			
		}
		else{
			CLR_BIT(PORTA,PIN);
		}
		break;
		case 'B':
		case 'b':
		if(valu==1)
		
		{
			SET_BIT(PORTB,PIN);
			
		}
		else{
			CLR_BIT(PORTB,PIN);
		}
		break;
		case 'C':
		case 'c':
		
		if(valu==1)
		
		{
			SET_BIT(PORTC,PIN);
			
		}
		else{
			CLR_BIT(PORTC,PIN);
		}
		break;
		case 'D':
		case 'd':
		
		if(valu==1)
		
		{
			SET_BIT(PORTD,PIN);
			
		}
		else{
			CLR_BIT(PORTD,PIN);
		}
	break;
	default:
	break;
	}	
	}
	void DIO_TogPin(unsigned char PORT,unsigned char PIN)
	{
		
		switch(PORT)
		{
		case 'A':
		case 'a':
		TOG_BIT(PORTA, PIN);
		break;
		case 'B':
		case 'b':
	    TOG_BIT(PORTB, PIN);
		break;
		
			case 'C':
			case 'c':
			TOG_BIT(PORTC, PIN);
			break;
			case 'D':
			case 'd':
			TOG_BIT(PORTD, PIN);
			break;
			default:
			break;
			
		}
	}
unsigned char DIO_u8Read(unsigned char PORT,unsigned char PIN)
	{
		unsigned char val=0;
		
		switch(PORT)
		{
			
			case'A':
			case 'a':
			val= Read_BIT(PINA,PIN);
			break;
			case'B':
			case 'b':
			val= Read_BIT(PINB,PIN);
			break;
			case'C':
			case 'c':
			val= Read_BIT(PINC,PIN);
			break;
			case'D':
			case 'd':
			val= Read_BIT(PIND,PIN);
			break;
			default:
			break;
		}
		return val;
	}
	void DIO_SetPortDirection(unsigned char PORT,unsigned char direction)
	{
	switch (PORT)
	{
	case 'A':
	case 'a':
	DDRA= direction;
	break;
	
	case 'B':
	case 'b':
	DDRB= direction;
	break;
	
	case 'C':
	case 'c':
	DDRC= direction;
	break;
	
	case 'D':
	case 'd':
	DDRD= direction;
	break;
	default:
	break;	
	}	
		
	}
	void DIO_WritePort(unsigned char PORT,unsigned char PortTValue)
	{
		
		switch(PORT)
		{
		case 'A':
		case 'a':
		PORTA= PortTValue;
			break;
			case 'B':
			case 'b':
			PORTB= PortTValue;
			break;
			case 'C':
			case 'c':
			PORTC= PortTValue;
			break;
			case 'D':
			case 'd':
			PORTD= PortTValue;
			break;
			default:
			break;
			
		}
	}
	 unsigned char DIO_Read_Port(unsigned char PORT)
	 {
		 unsigned char return_val=0 ;
		 switch(PORT)
		 {
			 case 'A':
			 case 'a':
			return_val =PINA;
			break;
			  case 'B':
			  case 'b':
			  return_val =PINB;
			  break;
			  
			   case 'C':
			   case 'c':
			   return_val =PINC;
			   break;
			   
			    case 'D':
			    case 'd':
			    return_val =PIND;
			    break;
				default:
				break;
		 }	
		 return  return_val;		    
	 }
	void DIO_TOG_PORT(unsigned char PORT)
	{
		switch (PORT)
		{
			
			case 'A':
			case 'a':
			PORTA =~PORTA;
			break;
			case 'B':
			case 'b':
			PORTB =~PORTB;
			break;
			case 'C':
			case 'c':
			PORTC=~PORTC;
			break;
			case 'D':
			case 'd':
			PORTD =~PORTD;
			break;
			default:
			break;		
		}
	}
	void DIO_Connect_Pullup(unsigned char PORT,unsigned char PIN,unsigned char connect)
	{
		switch (PORT)
		{
			
			case 'A':
			case 'a':
			if (connect==0)
			
			{
				SET_BIT(PORTA,PIN);
			}
			else{
				CLR_BIT(PORTA,PIN);
			
			}		
			case 'B':
			case 'b':
			if (connect==1)
			
			{
				SET_BIT(PORTB,PIN);
			}
			else{
				CLR_BIT(PORTB,PIN);
			}
		
			case 'C':
			case 'c':
			if (connect==1)
			
			{
				SET_BIT(PORTC,PIN);
			}
			else{
				CLR_BIT(PORTC,PIN);
			}
		
			case 'D':
			case 'd':
			if (connect==1)
			
			{
				SET_BIT(PORTD,PIN);
			}
			else{
				CLR_BIT(PORTD,PIN);
			}
		}
	}
 void DIO_Write_Low_Nibbl(unsigned char PORT,unsigned char valu)
 {
	  DIO_WritePin(PORT,0,Read_BIT(valu,0));
	   DIO_WritePin(PORT,1,Read_BIT(valu,1));
	    DIO_WritePin(PORT,2,Read_BIT(valu,2));
		 DIO_WritePin(PORT,3,Read_BIT(valu,3));
 }
 void DIO_Write_High_Nibbl(unsigned char PORT,unsigned char valu)
 {
	 DIO_WritePin(PORT,4,Read_BIT(valu,4));
	 DIO_WritePin(PORT,5,Read_BIT(valu,5));
	 DIO_WritePin(PORT,6,Read_BIT(valu,6));
	 DIO_WritePin(PORT,7,Read_BIT(valu,7));
 }