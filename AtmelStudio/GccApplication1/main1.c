/*
 * main.c
 *
 * Created: 6/7/2021 8:08:13 PM
 *  Author: dilsh
 */ 
#define F_CPU 18000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <lcd4bit.h>
#include <adc.h>
#include <tools.h>
#include <pwm.h>
#include <keypad.h>


int main(){
	//initPwm(3);
	lcd4init();
	//pwm(3,20);
	_delay_ms(500);
	lcd4print("Press 1 ADC");
	//pwm(3,0);
	//initkey();
	//initPwm(6);
	//initPwm(5);
	//initPwm(3);
	//while(1){
	//	
	//	_delay_ms(1000);
	//	lcd4clr();
	//	_delay_ms(1000);
	//}
	
	//gotoNewline();
	//char c = waitforkey();
	//if(c=='1'){
	//	lcd4print("Hi");
	//}
		
	
}
