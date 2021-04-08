#include <Keypad.h>

#include <LiquidCrystal.h>



const byte rows = 4; //four rows
	const byte cols = 4; //three columns
	char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {A0,A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[cols] = {A4, A5, 7 }; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
LiquidCrystal lcd(12, 8, 5, 4, 3, 2);
char rgb[9];
int size = 0;

void setup()
{
    Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(" R  G  B ");
  lcd.setCursor(0, 1);
}

void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY){
    if(key == '#'){
   	 lcd.begin(16,2);
      lcd.print(" R  G  B ");
  		lcd.setCursor(0, 1);
    }else if(key == '*'){
      while(keypad.getKey() == NO_KEY){
        int R = 100*((int)rgb[0]-(int)'0')+10*((int)rgb[1]-(int)'0')+1*((int)rgb[2]-(int)'0');
    int G = 100*((int)rgb[3]-(int)'0')+10*((int)rgb[4]-(int)'0')+1*((int)rgb[5]-(int)'0');
     int B = 100*((int)rgb[6]-(int)'0')+10*((int)rgb[7]-(int)'0')+1*((int)rgb[8]-(int)'0');
    Serial.println(R);
         Serial.println(G);
         Serial.println(B);
        analogWrite(11,R);
    analogWrite(9,G);
     analogWrite(10,B);
      };
      analogWrite(11,0);
    analogWrite(9,0);
     analogWrite(10,0);
      lcd.begin(16,2);
      lcd.print(" R  G  B ");
  	lcd.setCursor(0, 1);
    
    }else{
      rgb[size] = key;
      size++;
    lcd.print(key);
    }
  }
  
  // print the number of seconds since reset:
  
  
}