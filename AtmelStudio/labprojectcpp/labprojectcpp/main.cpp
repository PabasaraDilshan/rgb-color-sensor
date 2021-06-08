/*
 * labprojectcpp.cpp
 *
 * Created: 6/8/2021 12:03:14 AM
 * Author : dilsh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <Lcd4bit.h>

int main(void)
{
    /* Replace with your application code */
	Lcd4bit lcd(1);
	lcd.lcd4init();
    while (1) 
    {
    }
}

