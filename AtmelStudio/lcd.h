#define  LCD_DDDR DDRD
#define LCD_DPIN PIND
#define LCD_DPRT  PORTD
#define  LCD_CDDR DDRC
#define  LCD_CPIN  PINC
#define  LCD_CPRT  PORTC
#define  LCD_RS  2
#define  LCD_RW  1
#define  LCD_EN  0
void lcdinit();
void lcdcommand(int data);
void lcddata(int data);
void lcdprint(char* string);



void lcdinit(){
	LCD_DDDR = 0xFF; //PORTD as Output
	LCD_CDDR = 0xFF; //PORTC as Output
	LCD_CPRT &= ~(1<<LCD_EN);//EN =0
	_delay_ms(2);
	lcdcommand(0x0E);//display on, cursor on
	lcdcommand(0x01);//clear display
	
}
void lcdcommand(int data){
	LCD_DPRT = data;
	LCD_CPRT &= ~(1<<LCD_RS); //RS=0
	LCD_CPRT &= ~(1<<LCD_RW); //RW = 0
	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN);
	_delay_us(100);
	_delay_ms(2);
	
	
}

void lcddata(int data){
	LCD_DPRT = data;
	LCD_CPRT |= (1<<LCD_RS); //RS=1
	LCD_CPRT &= ~(1<<LCD_RW); //RW=0
	LCD_CPRT |= (1<<LCD_EN); //EN = 1
	_delay_us(1);
	LCD_CPRT &= ~(1<<LCD_EN); //EN=0
	_delay_us(100);
	_delay_ms(2);
}
void lcdprint(char* string){
	unsigned int i = 0;
	while(string[i]!=0){
		
		lcddata((int)(string[i]));
		i++;
	}
	
}