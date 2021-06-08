/*
 * RGBLED.c
 *
 * Created: 5/17/2021 11:21:38 PM
 * Author : Nimesh Kavshal
 */ 
#define F_CPU  8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LCD_DPRT PORTC
#define LCD_DDDR DDRC
#define LCD_DPIN PINC
#define LCD_CPRT PORTD
#define LCD_CDDR DDRD
#define LCD_CPIN PIND
#define LCD_RS 0
#define LCD_RW 1
#define LCD_EN 2

double value,red,green,blue;

ISR(TIMER0_OVF_vect){
	OCR0A = red;
	OCR0B = green;
}

ISR(TIMER2_OVF_vect){
	OCR2B = blue;
}

ISR(ADC_vect){
	value = ADC;
}

void lcdCommand(unsigned char cmnd)
{
	LCD_DPRT = ((cmnd & 0xF0)>>3);
	LCD_CPRT &= ~(1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	LCD_DPRT = ((cmnd<<4)>>3);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
}

void lcdData(unsigned char data)
{
	LCD_DPRT = ((data & 0xF0)>>3);
	LCD_CPRT |= (1<<LCD_RS);
	LCD_CPRT &= ~(1<<LCD_RW);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	LCD_DPRT = ((data<<4)>>3);
	LCD_CPRT |= (1<<LCD_EN);
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
}

void lcdInit()
{
	LCD_DDDR = 0xFF;
	LCD_CDDR = 0xFF;
	LCD_CPRT &= ~(1<<LCD_EN);
	lcdCommand(0x33);
	lcdCommand(0x32);
	lcdCommand(0x28);
	lcdCommand(0x0E);
	lcdCommand(0x01);
	_delay_us(2000);
	lcdCommand(0x06);
}

void lcdGotoXY(unsigned char x, unsigned char y)
{
	unsigned char firstCharAdr[]={0x80, 0xC0};
	lcdCommand(firstCharAdr[y-1] + x - 1);
	_delay_us(100);
}

void lcdPrintStr(char*str)
{
	unsigned char i = 0;
	while (str[i] != 0)
	{
		lcdData(str[i]);
		i++;
	}
}

void lcdPrintChar(char character)
{
	int temp = character;
	lcdData(temp);
}

void keypadInit()
{
	DDRB = 0b00001111;
	PORTB = 0b11110000;
}

int isKeypress()
{
	_delay_ms(200);
	PORTB = 0b11110000;
	if ((PINB & 0b11110000) == 0b11110000){
		return 0;
	return 1;
	}
}

char getKey()
{
	int row, col, x;
	char charArray[4][4] = {{ '7', '4', '1', 'N'}, { '8', '5', '2', '0'}, { '9', '6', '3', '='}, { '/', '*', '-', '+'}};	
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
			//return charArray[1][1];
			col = j;
			for (int i = 4 ; i<=7 ; i++){
				if (x & (1<<i)){
					continue;
				}
				else{
					row = i-4;
					return charArray[row][col];
				}
			}
		}
		else{
			continue;
		}
	}
}

void pwmInit()
{
	DDRD = (1<<PORTD6) | (1<<PORTD5) | (1<<PORTD3);

	TCCR2A = (1<<WGM20) | (1<<WGM21) | (1<<COM2B1);
	TCCR0A = (1<<WGM00) | (1<<WGM01) | (1<<COM0A1) | (1<<COM0B1);
	
	TIMSK0 = (1<<TOIE0);
	TIMSK2 = (1<<TOIE2);
	
	sei();
	
	TCCR0B = (1<<CS00) | (1<<CS02);
	TCCR2B = (1<<CS20) | (1<<CS22);
}

void startConv(){
	ADCSRA |= (1<<ADSC);
}

void ADCInit(){
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
	DIDR0 = (1<<ADC1D);
	sei();
	startConv();
}

int main(void)
{
    while (1) 
    {		

    }
}



