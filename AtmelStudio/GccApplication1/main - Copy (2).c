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
	char c = waitforkey();
	if(c=='1'){
		lcd4print("Hi");
	}
		
	
}
