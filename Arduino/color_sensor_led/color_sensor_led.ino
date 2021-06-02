int red,blue,green,all;
int redw,bluew,greenw,allw;
int redb,blueb,greenb,allb;
int rederr,blueerr,greenerr;
int truered,trueblue,truegreen;
int scaledred,scaledblue,scaledgreen;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Press Enter to Start");
  while(!Serial.available());
  Serial.read();
  Serial.println("Put White Paper and Press Enter");
  while(!Serial.available());
  Serial.read();
  redw = analogRead(A0);
  greenw = analogRead(A1);
  bluew = analogRead(A2);
  allw = analogRead(A3);
  Serial.print("redw-");
  Serial.print(redw);
  Serial.print(", greenw-");
  Serial.print(greenw);
  Serial.print(", bluew-");
  Serial.print(bluew);
  Serial.print(", allw-");
  Serial.print(allw);
  Serial.print("\n");
  Serial.println("Put Black Paper");
  while(!Serial.available());
  Serial.read();
  redb = analogRead(A0);
  greenb = analogRead(A1);
  blueb = analogRead(A2);
  allb = analogRead(A3);
  Serial.print("redb-");
  Serial.print(redb);
  Serial.print(", greenb-");
  Serial.print(greenb);
  Serial.print(", blueb-");
  Serial.print(blueb);
  Serial.print(", allb-");
  Serial.print(allb);
  Serial.print("\n");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Enter Color Name: ");
  while(!Serial.available());
  Serial.print(Serial.readStringUntil('\n'));
  Serial.print("\n");
  Serial.println("Put Paper");
  while(!Serial.available());
  Serial.read();
  red = analogRead(A0);
  green = analogRead(A1);
  blue = analogRead(A2);
  all = analogRead(A3);
  scaledred = ((float)(red-redb)/(float)(redw-redb))*255;
  scaledgreen = ((float)(green-greenb)/(float)(greenw-greenb))*255;
  scaledblue = ((float)(blue-blueb)/(float)(bluew-blueb))*255;
  Serial.print("red-");
  Serial.print(red);
  Serial.print(", green-");
  Serial.print(green);
  Serial.print(", blue-");
  Serial.print(blue);
  Serial.print(", all-");
  Serial.print(all);
  Serial.print("\n");
  Serial.println("Enter Color Values");
  while(!Serial.available());
  truered = Serial.readStringUntil(' ').toInt();
  truegreen = Serial.readStringUntil(' ').toInt();
  trueblue = Serial.readStringUntil('\n').toInt();
  Serial.print("redread: ");
  
  Serial.print(scaledred);
  Serial.print(" greenread: ");
  Serial.print(scaledgreen);
  Serial.print(" blueread: ");
  Serial.print(scaledblue);
  Serial.print("\n");
  
  Serial.print("rederr: ");
  Serial.print(scaledred-truered);
  Serial.print(" greenerr: ");
  Serial.print(scaledgreen-truegreen);
  Serial.print(" blueerr: ");
  Serial.print(scaledblue-trueblue);
  Serial.print("\n");
  Serial.print("\n");

}
