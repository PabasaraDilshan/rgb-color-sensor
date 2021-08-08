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

int redread,greenread,blueread;

void lightuprgb(){
	initPwm(6);
	initPwm(5);
	initPwm(3);
	lcd4clr();
	lcd4print("RRRGGGBBB");
	gotoNewline();
	int red =0;
	int green = 0;
	int blue = 0;
	char inp[9][1];
	int i = 0;
	while(i<9)
	{	
		char c = waitforkey();
		if(c=='*'){
			i=0;
			lcd4clr();
			lcd4print("RRRGGGBBB");
			gotoNewline();
			continue;
			
		}
		inp[i][0] = c;
		lcd4printlen(inp[i],1);
		i++;
		
	}
	for(int j =0; j<3;j++){
		red = red*10+(int)inp[j][0]-(int)'0';
		green = green*10+(int)inp[j+3][0]-(int)'0';
		blue = blue*10+(int)inp[j+6][0]-(int)'0';
	}
	
	/*
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
		
	}*/
	lcd4print("finish");
	pwm(6,255-red);
	pwm(5,255-green);
	pwm(3,255-blue);
	while(1){
		char c = waitforkey();
		if(c=='#'){
			break;
		}
	}
	pwm(6,0);
	pwm(5,0);
	pwm(3,0);
	
	
}
int getreading(){
	initAdc();
	
	lcd4clr();
	lcd4print("Value ");
	int read = readAdc(4);
	lcd4print(intos(read));
	return read;

}
void sensorreading(){
	lcd4clr();
	lcd4print("Press key, red");
	waitforkey();
	redread = getreading();
	gotoNewline();
	lcd4print("Press key, green");
	waitforkey();
	greenread = getreading();
	gotoNewline();
	lcd4print("Press key, blue");
	waitforkey();
	blueread = getreading();
	lcd4clr();
	lcd4print(intos(redread));
	lcd4print(", ");
	lcd4print(intos(greenread));
	lcd4print(", ");
	lcd4print(intos(blueread));
	double* values = readingtorgb((double)redread,(double)greenread,(double)blueread);
	gotoNewline();
	lcd4print(intos((int)values[0]));
	lcd4print(", ");
	lcd4print(intos((int)values[1]));
	lcd4print(", ");
	lcd4print(intos((int)values[2]));
	
	
	while(1){
		char c = waitforkey();
		if(c=='#'){
			break;
		}
	}
}
int main(){
	while(1){
		lcd4init();
	initkey();
	//initPwm(6);
	//initPwm(5);
	//initPwm(3);
	lcd4print("Press 1 ADC");
	gotoNewline();
	/*
	while(1){
		char c = waitforkey();
		char cr[1];
		cr[0] = c;
		lcd4printlen(cr,1);
	}*/
	lcd4print("Press 2 RGB");
	char c = waitforkey();
	//char c ='1';
	if(c=='2'){
		lightuprgb();
	}else{
		sensorreading();

	}
		
	}
	
	
		
	
}
