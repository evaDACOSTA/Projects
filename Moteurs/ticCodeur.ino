#include<TimerOne.h>

volatile int ticCodeurG=0;
volatile int ticCodeurD=0;
volatile float vitesseG=0.;
volatile float vitesseD=0.;
const int pinInterG=18;
const int pinInterD=19;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Roue gauche
  pinMode(pinInterG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterG), CompteurG, RISING);
  //Roue droite
  pinMode(pinInterD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterD), CompteurD, RISING);

  Timer1.initialize(10000);
  Timer1.attachInterrupt(Calcul_Vitesse);
}
void CompteurG()
{
  //Serial.print("Nombre de tics codeurs : ");
  ticCodeurG++;
  //Serial.println(ticCodeur);
}
void CompteurD()
{
  //Serial.print("Nombre de tics codeurs : ");
  ticCodeurD++;
  //Serial.println(ticCodeur);
}

void Calcul_Vitesse()
{
  //Vitesse roue gauche
  vitesseG=(ticCodeurG/990.0)/0.01;
  Serial.println(vitesseG);
  ticCodeurG=0;
  // Vitesse roue droite
  //vitesseD=(ticCodeurD/990.0)/0.01;
  //Serial.println(vitesseD);
  //ticCodeurD=0;

}
void loop() {
  // put your main code here, to run repeatedly:

}
