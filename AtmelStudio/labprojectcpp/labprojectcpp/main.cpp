/*
 * labprojectcpp.cpp
 *
 * Created: 6/8/2021 12:03:14 AM
 * Author : dilsh
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <Lcd4bit.h>



class Inttostr{
	public:
	int len = 0;
	char* str;
	Inttostr(int num){
		
		this->str = this->itos(num,1);
	}



	char* itos(int num,int count){
		char* st;
		if(num<10){
			//st = new char[this->len];
			st = (char*)malloc(this->len*sizeof(char));
			st[this->len] = (char)(num+(int)'0');
			
			}else{
			int rem = num%10;
			st = itos(num/10,count+1);
			st[this->len] = 	(char)(rem+(int)'0');
		}
		
		this->len++;

		return st;
		
	}
	
	
	
	
};

int main(void)
{
    /* Replace with your application code */ 
	Lcd4bit lcd(1);
	lcd.lcd4init();
	lcd.lcd4printlen(Inttostr(55).str,Inttostr(55).len);
    while (1) 
    {
    }
}

