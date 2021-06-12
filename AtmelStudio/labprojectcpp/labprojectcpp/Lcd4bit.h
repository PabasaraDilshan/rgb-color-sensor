/*
 * IncFile1.h
 *
 * Created: 6/8/2021 3:23:46 AM
 *  Author: dilsh
 */ 
#ifndef LCD4BIT_H_
#define LCD4BIT_H_


#define  LCD_DDDR DDRD
#define LCD_DPIN PIND
#define LCD_DPRT  PORTD
#define  LCD_CDDR DDRC
#define  LCD_CPIN  PINC
#define  LCD_CPRT  PORTC
#define  LCD_RS  2
#define  LCD_RW  1
#define  LCD_EN  0



class Lcd4bit{
	public:
		int pin;
		Lcd4bit(int p){
			this->pin = p;
		}
		void lcd4init(){
		
		LCD_DDDR |= 0xF0; //PORTD as Output
		LCD_CDDR |= 0x07; //PORTC as Output
		
		
		LCD_CPRT &= ~(1<<LCD_EN);//EN =0
		_delay_ms(2);
		this->lcd4command(0x33);//init lcd with 4bit
		this->lcd4command(0x32);//init lcd with 4bit
		this->lcd4command(0x28);//init lcd with 4bit
		this->lcd4command(0x0E);//display on, cursor on
		this->lcd4command(0x01);//clear display
		
		
		this->lcd4command(0x06);//shift cursor to right
		
	}
		void lcd4command(int data){
		LCD_DPRT = (LCD_DPRT &0x0F)| (data & 0xF0);
		LCD_CPRT &= ~(1<<LCD_RS); //RS=0
		LCD_CPRT &= ~(1<<LCD_RW); //RW = 0
		LCD_CPRT |= (1<<LCD_EN); //EN = 1
		_delay_us(1);
		LCD_CPRT &= ~(1<<LCD_EN);
		_delay_us(100);
		LCD_DPRT =  (LCD_DPRT &0x0F)|(data<<4);

		LCD_CPRT |= (1<<LCD_EN); //EN = 1
		_delay_us(1);
		LCD_CPRT &= ~(1<<LCD_EN);
		_delay_us(100);
		_delay_ms(2);
		
		
	}

		void lcd4data(int data){
		LCD_DPRT =  (LCD_DPRT &0x0F)| (data & 0xF0);
		LCD_CPRT |= (1<<LCD_RS); //RS=1
		LCD_CPRT &= ~(1<<LCD_RW); //RW=0
		LCD_CPRT |= (1<<LCD_EN); //EN = 1
		_delay_us(1);
		LCD_CPRT &= ~(1<<LCD_EN); //EN=0
		_delay_us(100);
		
		LCD_DPRT = (LCD_DPRT &0x0F)|(data<<4);
		LCD_CPRT |= (1<<LCD_EN); //EN = 1
		_delay_us(1);
		LCD_CPRT &= ~(1<<LCD_EN); //EN=0
		_delay_us(100);
		_delay_ms(2);
	}
		void lcd4print(const char* string){
		unsigned int i = 0;
		while(string[i]!=0){
			
			this->lcd4data((int)(string[i]));
			i++;
		}
		
	}
		void lcd4printlen(char* string, unsigned int length){
		unsigned int i = 0;
		for(i=0;i<length;i++){
			
			this->lcd4data((int)(string[i]));

		}
		
	}
		void lcd4clr(){
		this->lcd4command(0x01);
	}

	
	
	
};







#endif