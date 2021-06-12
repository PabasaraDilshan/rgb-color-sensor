/*
 * lcd.h
 *
 * Created: 4/27/2021 1:40:38 AM
 *  Author: dilsh
 */ 




#define  LCD_DDDR DDRC
#define LCD_DPIN PINC
#define LCD_DPRT  PORTC
#define  LCD_CDDR DDRD
#define  LCD_CPIN  PIND
#define  LCD_CPRT  PORTD
#define  LCD_RS  0
#define  LCD_RW  1
#define  LCD_EN  2
void lcd4init();
void lcd4command(int data);
void lcd4data(int data);
void lcd4print(char* string);
void lcd4printlen(char* string,int length);
void lcd4clr();



void lcd4init(){
	
	//LCD_DDDR |= 0xF0; //PORTD as Output
	LCD_DDDR |= 0x1E;
	LCD_CDDR |= 0x07; //PORTC as Output
	
	
	LCD_CPRT &= ~(1<<LCD_EN);//EN =0
	_delay_ms(2);
	lcd4command(0x33);//init lcd with 4bit
	lcd4command(0x32);//init lcd with 4bit
	lcd4command(0x28);//init lcd with 4bit
	lcd4command(0x0E);//display on, cursor on
	lcd4command(0x01);//clear display
	
	
	lcd4command(0x06);//shift cursor to right
	
}
void lcd4command(int data){
	LCD_DPRT = (LCD_DPRT & ~(0x1E))| ((data & 0xF0)>>3);
	LCD_CPRT &= ~(1<<LCD_RS); //RS=0
	LCD_CPRT &= ~(1<<LCD_RW); //RW = 0
	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	LCD_DPRT =  (LCD_DPRT &~(0x1E))|((data<<1)&0x1E);

	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	_delay_ms(2);
	
	
}

void lcd4data(int data){
	LCD_DPRT =  (LCD_DPRT &~(0x1E))| ((data & 0xF0)>>3);
	LCD_CPRT |= (1<<LCD_RS); //RS=1
	LCD_CPRT &= ~(1<<LCD_RW); //RW=0
	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN); //EN=0
	_delay_us(100);
	
	LCD_DPRT =  (LCD_DPRT &~(0x1E))|((data<<1)&0x1E);
	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN); //EN=0
	_delay_us(100);
	_delay_ms(2);
}
void lcd4print(char* string){
	unsigned int i = 0;
	while(string[i]!=0){
		
		lcd4data((int)(string[i]));
		i++;
	}
	
}
void lcd4printlen(char* string, int length){
	unsigned int i = 0;
	for(i=0;i<length;i++){
		
		lcd4data((int)(string[i]));

	}
	
}
void lcd4clr(){
	lcd4command(0x01);
}
void gotoNewline(){
	lcd4command(0xC0);
}


 /* LCD_H_ */