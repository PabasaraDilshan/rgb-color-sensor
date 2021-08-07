#include<math.h>
double red,green,blue;
int redw,greenw,bluew;
int redb,greenb,blueb;
float redscaled,greenscaled,bluescaled;
double light;
double calR,calB,calG;
//double theta[3][11] = {{ 7.80644240e+02, -4.13541438e+00,  1.59315003e+00, -3.45407759e+00,
//       -9.54168462e-04, -2.08982170e-03,  2.71439925e-03, -6.38481761e-06,
//        7.25086177e-03,  5.62079704e-03, -6.56728901e-04}, { 5.17850799e+03, -7.95412008e+00, -8.00483746e+00, -7.77173139e+00,
//       -6.37863401e-04, -2.08148107e-04, -4.29135121e-03, -1.52957332e-05,
//        9.63670908e-03,  1.34797074e-02,  1.59249269e-02}, { 2.40181999e+03, -5.53947782e+00, -2.49122749e+00, -4.34062003e+00,
//       -4.89891584e-04,  1.92371330e-03,  4.32416302e-03, -9.86222636e-06,
//        6.19024560e-03,  9.65242368e-03, -1.46407617e-03}};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5,OUTPUT);//Blue
  pinMode(6,OUTPUT);//Red
  pinMode(7,OUTPUT);//Green
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  light = 0;
  for(int i=0;i<1000;i++){
    light+=analogRead(A0);
    
  }
  light = light/1000;
  Serial.println(light);
  
  Serial.println("Put the White Paper");
  readcolors();
  redw = red;
  greenw = green;
  bluew = blue;
  Serial.println(redw);
  Serial.println(greenw);
  Serial.println(bluew);
  Serial.println("Put the Black Paper");
  readcolors();
  redb = red;
  greenb = green;
  blueb = blue;
  Serial.println(redb);
  Serial.println(greenb);
  Serial.println(blueb);
}

void loop() {
  // put your main code here, to run repeatedly:
  

  Serial.print("Put the Color Paper at ");
  Serial.println(light);
  readcolors();
  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);
//  double Xarr[] = {1,red,green,blue,red*red,green*green,blue*blue,red*green*blue,red*green,red*blue,green*blue};
  //redscaled = (float)(red-redb)/(float)(redw-redb);
 //greenscaled = (float)(green-greenb)/(float)(greenw-greenb);
 //bluescaled = (float)(blue-blueb)/(float)(bluew-blueb);
  
  

}
void readcolors(){
  
  red = 0;
  blue = 0;
  green = 0;
  while(!Serial.available());
  Serial.read();
  digitalWrite(5,HIGH);
  delay(100);
  for(int i=0;i<10000;i++){
    blue+=analogRead(A0);
  }
  //Serial.println("OFF");
  digitalWrite(5,LOW);
  delay(100);
  digitalWrite(6,HIGH);
  blue = blue/10000 ;
  delay(100);
  for(int i=0;i<10000;i++){
    red+=analogRead(A0);
  }
  digitalWrite(6,LOW);
  delay(100);
  digitalWrite(7,HIGH);
  red = red/10000 ;
  delay(100);
  for(int i=0;i<10000;i++){
    green+=analogRead(A0);
  }
  digitalWrite(7,LOW);
  green = green/10000 ;
  
  delay(100);
}
