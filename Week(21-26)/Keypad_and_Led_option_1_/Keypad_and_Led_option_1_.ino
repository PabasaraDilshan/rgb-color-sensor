#include <Keypad.h>

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

void setup() {
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
}



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
  int R=Enter_keys('R');
  int G=Enter_keys('G');
  int B=Enter_keys('B');
  delay(1000);
  Serial.println(R);
  Serial.println(G);
  Serial.println(B);
  
  if(R<257 and G<257 and B<257){
    analogWrite(A0,B);
    analogWrite(A1,G);
    analogWrite(A2,R);
    Serial.println("OKAy");
  }
  else{
    Serial.println("Invalid inputs");
  }
  delay(2000);
}

void loop() {
  Input_for_LED();
}
