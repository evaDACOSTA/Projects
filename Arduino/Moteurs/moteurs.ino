int sens=0;
char chaine="";
int buffer=0;

void avance(){
  analogWrite(2,85);
  analogWrite(3,255);
  analogWrite(4,0);
  analogWrite(7,100);
  analogWrite(6,0);
  analogWrite(5,255);
}
void gauche(){
  analogWrite(2,85);
  analogWrite(3,255);
  analogWrite(4,0);
  analogWrite(7,100);
  analogWrite(6,255);
  analogWrite(5,0);

}
void droite(){
  analogWrite(2,85);
  analogWrite(3,0);
  analogWrite(4,255);
  analogWrite(7,100);
  analogWrite(6,0);
  analogWrite(5,255);
}
void demiTour()
{
  analogWrite(2,85);
  analogWrite(3,255);
  analogWrite(4,0);
  analogWrite(7,100);
  analogWrite(6,255);
  analogWrite(5,0);
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  avance();
  delay(3000);
  droite();
  delay(600);
  avance();
  delay(3000);
  droite();
  delay(1200);
  avance();
  delay(3000);
  gauche();
  delay(600);

    
}
