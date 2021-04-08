#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


int x = 0,r1 =0 ,c1 = 0;
char key;
int rgb[10] = {0,0,0,0,0,0,0,0,0,0};


char keys[4][3] = {{'1','2','3'}, {'4','5','6'},{'7','8','9'},{'*','0','#'}};
void search();
void input(char c);
void command (unsigned char cmd)
{
	PORTC = 0X02;
	PORTD = cmd;
	PORTC = 0X00;
	_delay_ms(15);
}
void lcd_data(unsigned char data)
{
	PORTC = 0X03;
	PORTD = data;
	PORTC = 0X01;
	_delay_ms(15);
}
void lcd_print(char *p)
{
	while(*p)
	{
		lcd_data(*p++);
	}
}
int main(void)
{
	DDRB = 0XF0;
	PORTB = 0X0F;
	DDRC=0XFF;//This register is used for selecting the R/S and R/W pin.
	DDRD=0XFF;//This register is used to give the data or commands.
	command(0x38);//Activated 2 lines in 8-bit mode.
	command(0X0F);//Display is ON, cursor is blinking.
	command(0x01);//Clearing the display.
	command(0X80);//Forced the cursor to first position of first line.
	
	
	
	
	while(1)
	{
		if(rgb[9]!=9){
			while(1)
			{
				x=PINB;
				if(x!=0x0f)
				{
					break;
				}
				
			}
			
			PORTB=0xEF;
			x=PINB;
			if(x!=0XEF)
			{
				r1=0;
				search();
			}
			PORTB=0xDF;
			x=PINB;
			if(x!=0XDF)
			{
				r1=1;
				search();
			}
			PORTB=0xBF;
			x=PINB;
			if(x!=0XBF)
			{
				r1=2;
				search();
			}
			PORTB=0x7F;
			x=PINB;
			if(x!=0X7F)
			{
				r1=3;
				search();
			}
			
			
		
		
		/*
		_delay_ms(100);
		command(0XC0);//Forced the cursor to the first position of second line.
		lcd_print("SS EmbeddedWorld");
		_delay_ms(100);
		command(0X01);//Clearing the display.
		_delay_ms(100);*/
		}else{
			command(0X01);//Clearing the display.
			lcd_print((char*)&(rgb[2]));
			
		}
	}
}


void search()
{
	x= x & 0x0F;
	if(x==0x0E){
	key = keys[0][r1];
	rgb[rgb[9]] = (int)key;
	rgb[9]++;
	lcd_print(&key);
	
	}
	
	if(x==0x0D)
		{
			
			key = keys[1][r1];
			rgb[rgb[9]] = (int)key;
			rgb[9]++;
			lcd_print(&key);
		}
	
	if(x==0x0B)
		{
			key = keys[2][r1];
			rgb[rgb[9]] = (int)key;
			rgb[9]++;
			lcd_print(&key);
		}
	
	if(x==0x07)
		{
			key = keys[3][r1];
			
			if(key=='#'){
				command(0X01);//Clearing the display.
				rgb[9] = 0;
				
				}else{
					rgb[rgb[9]] = (int)key;
					rgb[9]++;
				lcd_print(&key);
			}
			
			
		}
}
