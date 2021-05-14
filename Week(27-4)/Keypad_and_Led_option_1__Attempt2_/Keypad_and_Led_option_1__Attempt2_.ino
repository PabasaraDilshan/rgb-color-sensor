#include <Keypad.h>
#include <LiquidCrystal.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {3,8,9,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11,12,13}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(1,2,4,5,6,7);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Welcome_disp(){
  lcd.clear();
  char welcome[]="Press * to input values or # to detect surface color.                ";
  lcd.print("Select the mode ");
  lcd.setCursor(0,0);
  delay(2000);
  lcd.clear();
  for(int i=0;i<54;i++){
    char mas[16]="                ";
    for(int j=0;j<17;j++){
      mas[j]=welcome[j+i];
    }
    lcd.print(mas);
    lcd.setCursor(0,0);
    delay(500);
  }
}

void Com_after_choice(int option){
  lcd.clear();
  if(option==1){
    lcd.print("Give 3 inputs");
  }
  else{
    lcd.print("Start in 5 sec");
  }
}

void disp_RGB(int R,int G,int B){
  lcd.clear();
  lcd.print("  R    G    B");
  lcd.setCursor(1,1);
  lcd.print(R);
  lcd.setCursor(6,1);
  lcd.print(G);
  lcd.setCursor(11,1);
  lcd.print(B);
  lcd.setCursor(0,0);
  delay(1000);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Enter_keys(char X){
  String Num="";
  while(Num.length()<3){
    char customKey = customKeypad.getKey();
    if(customKey){
      Num=Num+customKey;
    }
  }
  return Num.toInt();
}

void Input_for_LED(){
  lcd.clear();
  lcd.print("  R    G    B");
  int R=Enter_keys('R');
  lcd.setCursor(1,1);
  lcd.print(R);
  int G=Enter_keys('G');
  lcd.setCursor(6,1);
  lcd.print(G);
  int B=Enter_keys('B');
  lcd.setCursor(11,1);
  lcd.print(B);
  delay(5000);
  //Serial.println(R);
  //Serial.println(G);
  //Serial.println(B);
  
  if(R<257 and G<257 and B<257){
    analogWrite(A0,B);
    analogWrite(A1,G);
    analogWrite(A2,R);
    //Serial.println("OKAy");
  }
  else{
    lcd.clear();
    lcd.print("Invalid inputs");
    delay(2000);
    lcd.clear();
    lcd.print("Give new values");
    delay(1000);
    lcd.clear();
    lcd.print("Val shd <257");
    delay(1000);
    Input_for_LED();
    //Serial.println("Invalid inputs");
  }
  delay(5000);
  analogWrite(A0,0);
  analogWrite(A1,0);
  analogWrite(A2,0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  lcd.begin(16,2);
  //Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
}

void loop() {
  char customKey;
  Welcome_disp(); 
  String Num1="";
  while(Num1.length()<1){
    customKey = customKeypad.getKey();
    if(customKey){
      if((customKey=='*' or customKey=='#')){
        Num1=customKey;
      }
      else{
        lcd.print("Wrong Key bro");
      }
      
    }
  }
  lcd.clear();
  if (customKey=='#'){
  }
  else
  {
    lcd.print("You chose input");
    lcd.setCursor(0,1);
    lcd.print("RGB");
    delay(1000);
    Input_for_LED();
  }
  
}
