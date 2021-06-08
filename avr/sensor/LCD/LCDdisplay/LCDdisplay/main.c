#define F_CPU 8000000UL
#include <avr/io.h>
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

void lcdInit();
void lcdCommand(unsigned char cmnd);
void lcdData(unsigned char data);
void lcdGotoXY(unsigned char x, unsigned char y);
void lcdPrint();

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

void lcdPrint(char*str)
{
	unsigned char i = 0;
	while (str[i] != 0)
	{
		lcdData(str[i]);
		i++;
	}
}

/*void lcdPrint()
{
	lcdData(0x40);
}*/

int main (void)
{
	lcdInit();
	//_delay_ms(3000);
	lcdGotoXY(1,1);
	lcdPrint("HI");
	_delay_ms(1000);
	lcdGotoXY(10,1);
	lcdPrint("Hey");
	//_delay_ms(10000);
	while (1)
	{	
	}
	return(0);
}

