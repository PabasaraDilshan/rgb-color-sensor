/*
 * keypad_with_seven_segment.c
 *
 * Created: 26-03-2017 12:31:36 PM
 *  Author: CG-DTE
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
char database[4][4]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x012,0x13,0x14,0x15};
					 

void search();
int r1=0,c1=0;int x=0;

int main(void)

{
	DDRC=0xff;
	PORTC=0x00;
	DDRB=0xf0;
	PORTB=0x0f;
	while(1)

{
	
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
}
}
void search()
{
	x= x & 0x0F;
	if(x==0x0E)
	PORTC=database[r1][0];
	
	if(x==0x0D)
	PORTC=database[r1][1];
	
	if(x==0x0B)
	PORTC=database[r1][2];
	
	if(x==0x07)
	PORTC=database[r1][3];
}