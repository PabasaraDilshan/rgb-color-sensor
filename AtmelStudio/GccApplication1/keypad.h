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
	
	KEY_PRT &= 0xF0;
	col = (KEY_PIN & 0xF0 );
	while(col==0xF0){
		col = (KEY_PIN & 0xF0 );
	}

	while(1){
		KEY_PRT = 0xFE;
		col = (KEY_PIN & 0xF0 );
		if(col!=0xF0){
			row = 0;
			break;
		}
		KEY_PRT = 0xFD;
		col = (KEY_PIN & 0xF0 );
		if(col!=0xF0){
			row = 1;
			break;
		}
		KEY_PRT = 0xFB;
		col = (KEY_PIN & 0xF0 );
		if(col!=0xF0){
			row = 2;
			break;
		}
		KEY_PRT = 0xF7;
		col = (KEY_PIN & 0xF0 );
		if(col!=0xF0){
			row = 3;
			break;
		}
	}
	KEY_PRT = 0xFF;
	_delay_ms(20);
	if(col==0xE0){
		return keys[row][0];
	}
	if(col==0xD0){
		return keys[row][1];
	}
	
	return keys[row][2];
	
	
}



/*
boolean iskey(){
	
	
	
}
*/
