#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const byte numRows = 4;
const byte numCols = 4;
int whiteAnalogPin = A0;
int redAnalogPin = A3;
int greenAnalogPin = A2;
int blueAnalogPin = A1;
int powerUp = 10;

int white = 0;
int red = 0;
int green = 0;
int blue = 0;
char lastPressed = 'A';
int iter = 0;
int redDef = 0;
int greenDef = 0;
int blueDef = 0;
int whiteDef = 0;
int redFrac = 0;
int greenFrac = 0;
int blueFrac = 0;
int whiteFrac = 0;

int countDown = 3;
bool keyPressedFirstTime[4] = {true, true, true, true};

char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

int samples = 40;
int blackRGB[3] = {0, 0, 0};
int whiteRGB[3] = {0, 0, 0};
int colorRGB[3] = {0, 0, 0};
int mappedRGB[3] = {0, 0, 0};
bool detected = false;

void setup() {
  Serial.begin(9600);
  pinMode(powerUp, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  
//  white = analogRead(whiteAnalogPin);
//  red = analogRead(redAnalogPin);
//  green = analogRead(greenAnalogPin);
//  blue = analogRead(blueAnalogPin);

//  Serial.print("white: ");
//  Serial.print(white);
//  Serial.print("    ");
//  Serial.print("red: ");
//  Serial.print(red);
//  Serial.print("    ");
//  Serial.print("green: ");
//  Serial.print(green);
//  Serial.print("    ");
//  Serial.print("blue: ");
//  Serial.println(blue);
  
//  lcd.clear();
//  lcd.print(red);
  
  char keypressed = myKeypad.getKey();
  
  if(keypressed != NO_KEY) {
    Serial.println(keypressed);
    detected = false;
    lastPressed = keypressed;
//    Serial.print(keypressed);
    lcd.clear();
    lcd.print(keypressed);
  }

  if (lastPressed == 'A') {
    if (keyPressedFirstTime[0]) {
      for(int i = 0; i < 4; i++){
        keyPressedFirstTime[i] = true;
      }
      keyPressedFirstTime[0] = false;
      countDown = 3;
      digitalWrite(powerUp, LOW);
      lcd.clear();
      lcd.print("Waiting...");
    }
  }

  if (lastPressed == 'B') {
    if (keyPressedFirstTime[1]) {
      for(int i = 0; i < 4; i++){
        keyPressedFirstTime[i] = true;
      }
      keyPressedFirstTime[1] = false;
      countDown = 3;
      digitalWrite(powerUp, LOW);
    }
    lcd.clear();
    if (countDown >= 0){
      lcd.print("Black in ");
      lcd.print(countDown);
      delay(1000);
      countDown = countDown-1;
    } else {
      lcd.print("Reading black");
      digitalWrite(powerUp, HIGH);
      delay(50);
      blackRGB[0], blackRGB[1], blackRGB[2] = 0;
      Serial.println("#################### Black Values ####################");
      for (int i = 0; i<samples; i++){
        red = analogRead(redAnalogPin);
        green = analogRead(greenAnalogPin);
        blue = analogRead(blueAnalogPin);
        Serial.print("Red: ");
        Serial.print(red);
        Serial.print(", Green: ");
        Serial.print(green);
        Serial.print(", Blue: ");
        Serial.println(blue);
        blackRGB[0] += red;
        blackRGB[1] += green;
        blackRGB[2] += blue;
        delay(50);
      }
      blackRGB[0] /= samples;
      blackRGB[1] /= samples;
      blackRGB[2] /= samples;
      Serial.println("#################### Black Mean Values ####################");
      Serial.print("Red: ");
      Serial.print(blackRGB[0]);
      Serial.print(", Green: ");
      Serial.print(blackRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(blackRGB[2]);
      lastPressed = 'A';
    }
  }

  if (lastPressed == 'C') {
    if (keyPressedFirstTime[2]) {
      for(int i = 0; i < 4; i++){
        keyPressedFirstTime[i] = true;
      }
      keyPressedFirstTime[2] = false;
      countDown = 3;
      digitalWrite(powerUp, LOW);
    }
    lcd.clear();
    if (countDown >= 0){
      lcd.print("White in ");
      lcd.print(countDown);
      delay(1000);
      countDown = countDown-1;
    } else {
      lcd.print("Reading white");
      digitalWrite(powerUp, HIGH);
      delay(50);
      whiteRGB[0], whiteRGB[1], whiteRGB[2] = 0;
      Serial.println("#################### White Values ####################");
      for (int i = 0; i<samples; i++){
        red = analogRead(redAnalogPin);
        green = analogRead(greenAnalogPin);
        blue = analogRead(blueAnalogPin);
        Serial.print("Red: ");
        Serial.print(red);
        Serial.print(", Green: ");
        Serial.print(green);
        Serial.print(", Blue: ");
        Serial.println(blue);
        whiteRGB[0] += red;
        whiteRGB[1] += green;
        whiteRGB[2] += blue;
        delay(50);
      }
      whiteRGB[0] /= samples;
      whiteRGB[1] /= samples;
      whiteRGB[2] /= samples;
      Serial.println("#################### White Mean Values ####################");
      Serial.print("Red: ");
      Serial.print(whiteRGB[0]);
      Serial.print(", Green: ");
      Serial.print(whiteRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(whiteRGB[2]);
      lastPressed = 'A';
    }
  }

  if (lastPressed == 'D') {
    
    if (!detected){
      for (int i = 3; i > 0; i--){
        lcd.clear();
        lcd.print("Detecting in ");
        lcd.print(i);
        delay(1000);
      }
      
      lcd.clear();
      lcd.print("Detecting color");
      digitalWrite(powerUp, HIGH);
      delay(50);
      colorRGB[0], colorRGB[1], colorRGB[2] = 0;
      Serial.println("#################### Color Values ####################");
      for (int i = 0; i<samples; i++){
        red = analogRead(redAnalogPin);
        green = analogRead(greenAnalogPin);
        blue = analogRead(blueAnalogPin);
        Serial.print("Red: ");
        Serial.print(red);
        Serial.print(", Green: ");
        Serial.print(green);
        Serial.print(", Blue: ");
        Serial.println(blue);
        colorRGB[0] += red;
        colorRGB[1] += green;
        colorRGB[2] += blue;
        delay(50);
      }

      colorRGB[0] /= samples;
      colorRGB[1] /= samples;
      colorRGB[2] /= samples;
      
      Serial.println("#################### Black Mean Values ####################");
      Serial.print("Red: ");
      Serial.print(blackRGB[0]);
      Serial.print(", Green: ");
      Serial.print(blackRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(blackRGB[2]);
      
      Serial.println("#################### White Mean Values ####################");
      Serial.print("Red: ");
      Serial.print(whiteRGB[0]);
      Serial.print(", Green: ");
      Serial.print(whiteRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(whiteRGB[2]);
      
      Serial.println("#################### Color Mean Values ####################");
      Serial.print("Red: ");
      Serial.print(colorRGB[0]);
      Serial.print(", Green: ");
      Serial.print(colorRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(colorRGB[2]);

      Serial.println((colorRGB[0]-blackRGB[0]));
      Serial.println((colorRGB[0]-blackRGB[0])*255);
      //value (say for red) = (redValueForColorSurface-blackValueForBlackSurface)*255/(redValueForWhiteSurface-redValueforBlackSurface)
      
//      Serial.println((whiteRGB[0]-blackRGB[0]));
//      Serial.println(((colorRGB[0]-blackRGB[0])*255)/(whiteRGB[0]-blackRGB[0]));
      
      mappedRGB[0] = ((colorRGB[0]-blackRGB[0])*255)/(whiteRGB[0]-blackRGB[0]);
      mappedRGB[1] = ((colorRGB[1]-blackRGB[1])*255)/(whiteRGB[1]-blackRGB[1]);
      mappedRGB[2] = ((colorRGB[2]-blackRGB[2])*255)/(whiteRGB[2]-blackRGB[2]);
      Serial.println("#################### Final Color Values ####################");
      Serial.print("Red: ");
      Serial.print(mappedRGB[0]);
      Serial.print(", Green: ");
      Serial.print(mappedRGB[1]);
      Serial.print(", Blue: ");
      Serial.println(mappedRGB[2]);
      
      lcd.clear();
      if (mappedRGB[0]>mappedRGB[1] && mappedRGB[0]>mappedRGB[2]){
        lcd.println("RED");
      } else if (mappedRGB[1]>mappedRGB[2]) {
        lcd.println("GREEN");
      } else {
        lcd.println("BLUE");
      }
      detected = true;
      digitalWrite(powerUp, LOW);
    }
  }
  delay(50);
}
