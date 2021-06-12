/*
 * main.c
 *
 * Created: 6/7/2021 8:08:13 PM
 *  Author: dilsh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <lcd4bit.h>
#include <adc.h>
#include <tools.h>
#include <pwm.h>
#include <keypad.h>


int main(){
	lcd4init();
	initkey();
	//initPwm(6);
	//initPwm(5);
	//initPwm(3);
	lcd4print("Press 1 ADC");
	gotoNewline();
	while(1){
		char c = waitforkey();
		char cr[1];
		cr[0] = c;
		lcd4printlen(cr,1);
	}
	lcd4print("Press 2 RGB");
	char c = waitforkey();
	//char c ='1';
	if(c=='2'){
		lcd4clr();
		lcd4print("RRRGGGBBB");
		gotoNewline();
		int red =0;
		int green = 0;
		int blue = 0;
		char inp[1];
		for (int i =0; i<3;i++)
		{
			inp[0] = waitforkey();
			red = red*10+(int)inp[0]-(int)'0';
			lcd4printlen(inp,1);
			
		}
		for (int i =0; i<3;i++)
		{
			inp[0] = waitforkey();
			green = green*10+(int)inp[0]-(int)'0';
			lcd4printlen(inp,1);
			
		}
		for (int i =0; i<3;i++)
		{
			inp[0] = waitforkey();
			blue = blue*10+(int)inp[0]-(int)'0';
			lcd4printlen(inp,1);
			
		}
		pwm(6,255-red);
		pwm(5,255-green);
		pwm(3,255-blue);
		while(1);
	}else{
		initAdc();
		
		lcd4clr();
		lcd4print("Value ");
		lcd4print(itos(readAdc(6),1));
		while(1);

	}
	
		
	
}
