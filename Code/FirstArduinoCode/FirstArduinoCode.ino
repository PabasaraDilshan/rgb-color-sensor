void setup() {
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
int r;
int g;
int b;

void loop() {
  digitalWrite(7,HIGH);
  delay(3000);
  Serial.println("red");
  for (int i=0; i<5; i++){
    r = analogRead(A0);
    r = map(r,406,802,0,255);
    Serial.println(r);
    delay(500);
  }
  Serial.println();
  Serial.println("blue");
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(3000);
  for (int i=0; i<5; i++){
    b = analogRead(A0);
    b = map(b,271,666,0,255);
    Serial.println(b);
    delay(500);
  }
  Serial.println();
  Serial.println("green");
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(3000);
  for (int i=0; i<5; i++){
    g = analogRead(A0);
    g = map(g,325,745,0,255);
    Serial.println(g);
    delay(1000);
  }
  Serial.println();
  digitalWrite(5,LOW);

}
