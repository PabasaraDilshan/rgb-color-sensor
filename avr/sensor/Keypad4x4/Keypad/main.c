/*
 * sensor.c
 *
 * Created: 5/4/2021 12:39:04 PM
 * Author : Nimesh Kavshal
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0b00001111;
	PORTB = 0b11110000;
	DDRD = 0b11111111;
	int row, col, x;
	char charArray[4][4] = {{ '7', '4', '1', 'N'}, { '8', '5', '2', '0'}, { '9', '6', '3', '='}, { '/', '*', '-', '+'}};
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(100);
		PORTB = 0b11110000;
		if ((PINB & 0b11110000) == 0b11110000){
			continue;
		}
		else{
			for (int j = 0; j<=3; j++){
				PORTB = 0b11110000;
				for (int k=0; k<j; k++){
					PORTB|=(1<<k);
				}
				for (int k = j+1; k<=3; k++){
					PORTB|=(1<<k);
				}
				x = PINB;
				if ((x & 0b11110000) != 0b11110000){
					col = j;
					for (int i = 4 ; i<=7 ; i++){
						if (x & (1<<i)){
							continue;
						}
						else{
							row = i-4;
							PORTD = 0b1<<row | 0b1<<col;
							_delay_ms(100);
							PORTD = 0b00000000;
							break;
						}
					}					
				}
				else{
					continue;	
				}
				break;
			}

		}
    }
}

