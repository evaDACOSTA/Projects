int periode = 1000;
float tension=0;
int rapport=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){}
  pinMode(26,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tension=analogRead(1);
  rapport=periode*tension/1023;

  digitalWrite(26,HIGH);
  delay(rapport);
  digitalWrite(26,LOW);
  delay(periode-rapport);
}
