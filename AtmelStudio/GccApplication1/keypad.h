/*
 * keypad.h
 *
 * Created: 4/27/2021 12:19:59 PM
 *  Author: dilsh
 */ 


#define KEY_DDR  DDRB
#define KEY_PIN  PINB
#define KEY_PRT  PORTB
int col,row;
unsigned char keys[4][3] = {'1','2','3','4','5','6','7','8','9','*','0','#'};
void initkey(){
	KEY_DDR = 0x0F;
	KEY_PRT = 0xFF;
}
char waitforkey(){
	

	do 
	{
		KEY_PRT &= 0x70;
		col = (KEY_PIN & 0x70 );
		
	} while (col!=0x70);
	do 
	{
		do 
		{
			_delay_ms(20);
			col = (KEY_PIN & 0x70 );
		} while (col == 0x70);
		_delay_ms(20);
		col = (KEY_PIN & 0x70 );
	} while (col==0x70);

	while(1){
		KEY_PRT = 0xFE;
		col = (KEY_PIN & 0x70 );
		if(col!=0x70){
			row = 0;
			break;
		}
		KEY_PRT = 0x7D;
		col = (KEY_PIN & 0x70 );
		if(col!=0x70){
			row = 1;
			break;
		}
		KEY_PRT = 0x7B;
		col = (KEY_PIN & 0x70 );
		if(col!=0x70){
			row = 2;
			break;
		}
		KEY_PRT = 0x77;
		col = (KEY_PIN & 0x70 );
		if(col!=0x70){
			row = 3;
			break;
		}
	}
	KEY_PRT = 0x7F;
	if(col==0x60){
		return keys[row][0];
	}
	if(col==0x50){
		return keys[row][1];
	}
	
	return keys[row][2];
	
	
}



/*
boolean iskey(){
	
	
	
}
*/
