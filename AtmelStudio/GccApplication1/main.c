/*
 * main.c
 *
 * Created: 4/18/2021 11:32:42 PM
 * Author : Pabsara Dilshan
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <keypad.h>
#include <lcd4bit.h>


int main(void)
{
	lcd4init();

	initkey();
	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		lcd4print("Test ");
 
		while(1){
			char c = waitforkey();
			lcd4printlen(&c,1);
			if(c=='#'){
				break;
			}
		}
		lcd4clr();
    }
}


