/* * calculator__project.c * * Created: 10/25/2024 1:18:52 PM *  Author: ghada_moemn */
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "KEYPAD.h"
#include "LCD.h"
#define IDLE_TIMEOUT 50 // Define the idle timeout period (in ms)

int main(void)
{
	unsigned char button;
	unsigned char op = 0;
	float num = 0;
	float result = 0;
	int calculator_on = 0; // Track whether the calculator is on
	unsigned long last_interaction_time = 0;
	int decimal_flag = 0;
	float decimal_place = 0.1;

	LCD_Initial();
	KeyPad_Initial();

	while (1)
	{
		button = KeyPad_Read();
		
		if (button == 'A')
		{
			if (!calculator_on)
			{
				calculator_on = 1; // Turn on the calculator
				LCD_CLR_Screen();
				LCD_Send_String("Calculator ON");
				_delay_ms(30);
				LCD_CLR_Screen();
			}
			else
			{
				num = 0;
				result = 0;
				op = 0;
				decimal_flag = 0;
				decimal_place = 0.1;
				LCD_CLR_Screen(); // Clear screen
				LCD_Send_String("Reset");
				_delay_ms(30);
				LCD_CLR_Screen();
			}
			last_interaction_time = 0; // Reset the idle timer
		}
		
		if (calculator_on)
		{
			if (button >= '0' && button <= '9')
			{
				if (decimal_flag)
				{
					num += (button - '0') * decimal_place;
					decimal_place *= 0.1;
				}
				else
				{
					num = (num * 10) + (button - '0');
				}
				LCD_Send_data(button);
				last_interaction_time = 0;
			}
			else if (button == '.')
			{
				decimal_flag = 1;
				LCD_Send_data(button);
			}
			else if (button == '+' || button == '-' || button == '*' || button == '/')
			{
				if (op == 0)
				{
					result = num;
				}
				else
				{
					switch (op)
					{
						case '+': result += num; break;
						case '-': result -= num; break;
						case '*': result *= num; break;
						case '/': result /= num; break;
					}
				}
				op = button;
				num = 0;
				decimal_flag = 0;
				decimal_place = 0.1;
				LCD_Send_data(button);
				last_interaction_time = 0;
			}
			else if (button == '=')
			{
				switch (op)
				{
					case '+': result += num; break;
					case '-': result -= num; break;
					case '*': result *= num; break;
					case '/': result /= num; break;
				}
				LCD_Send_data('=');
				LCD_Move_Cursor(2, 1); // Move to the second line, first column to display the result
				LCD_Send_String("Result=");
				LCD_Move_Cursor(2, 8);
				
				char buffer[16];
				dtostrf(result, 6, 2, buffer); // Convert float to string
				LCD_Send_String(buffer);
				
				num = 0;
				result = 0;
				op = 0;
				decimal_flag = 0;
				decimal_place = 0.1;
				last_interaction_time = 0;
			}
		}

		_delay_ms(50);
		last_interaction_time++;
		if (last_interaction_time >= IDLE_TIMEOUT)
		{
			calculator_on = 0; // Turn off the calculator
			LCD_CLR_Screen();
			LCD_Send_String("Calculator OFF");
			_delay_ms(200);
			LCD_CLR_Screen();
		}
	}
}
