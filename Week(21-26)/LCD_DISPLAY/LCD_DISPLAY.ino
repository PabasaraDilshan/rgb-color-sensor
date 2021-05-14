#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7);
void setup() {
  lcd.begin(16,2);
  
}


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


void loop() {
  Welcome_disp();
  delay(2000);
  Com_after_choice(10);
  delay(2000);
  disp_RGB(100,235,124);
  delay(2000);
}
