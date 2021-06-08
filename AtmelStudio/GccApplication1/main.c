/*
 * main.c
 *
 * Created: 6/7/2021 8:08:13 PM
 *  Author: dilsh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <lcd4cpp.h>

int main(){
	
	Lcd4bit lcd();
	lcd.lcd4init();
	while(1);
}
