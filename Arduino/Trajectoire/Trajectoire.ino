#include<TimerOne.h>
#include <LiquidCrystal.h>
#include <math.h>

const int rs = 33, en = 35, d4 = 37, d5 = 39, d6 = 41, d7 = 43;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temps=0;
unsigned int d=0;

const int ledJ_G=32;
const int ledJ_D=24;
const int ledR_G=30;
const int ledR_M=28;
const int ledR_D=26;

int asser=0;
int bouton=0;

float tension=0;
int valeur=0;

const int pinInterG=18;
const int pinInterD=19;

volatile float ticCodeurG=0.;
volatile float ticCodeurD=0.;
volatile float ticG=0.;
volatile float ticD=0.;

volatile float vitesseG=0.;
volatile float vitesseD=0.;
volatile float vitessePG=0.;
volatile float vitessePD=0.;

const float D_Roue=6.4;
const float pi = 3.14159;
volatile float vit_Depl=0.;

float Gmax=300;
volatile float tauI=50;

volatile float consigne=0.;

volatile float erreurG=0.;
volatile int commandeG=0;

volatile float sommeEG=0.;
volatile float erreurD=0.;
volatile int commandeD=0;

volatile float sommeED=0.;

void setup() 
{
  Serial.begin(115200);
  lcd.begin(16, 2);

  pinMode(52,INPUT_PULLUP);
  pinMode(ledJ_G,OUTPUT);
  pinMode(ledJ_D,OUTPUT);
  pinMode(ledR_G,OUTPUT);
  pinMode(ledR_M,OUTPUT);
  pinMode(ledR_D,OUTPUT);

  // Compteur tics codeurs de la roue gauche
  pinMode(pinInterG, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterG), CompteurG, RISING);

  //Compteur tics codeurs de la roue droite
  pinMode(pinInterD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterD), CompteurD, RISING);

  // Asservissement
  Timer1.initialize(20000);
  Timer1.attachInterrupt(Asservissement);
}
void CompteurG()
{
  ticCodeurG++;
}

void CompteurD()
{
  ticCodeurD++;  
}

void Asservissement()
{ if( asser==1)
  {
   
    
  vitessePG=vit_Depl;


  ticG=ticCodeurG;
  ticD=ticCodeurD;
  ticCodeurG=0;
  ticCodeurD=0;
  
  //Vitesse roue gauche
  vitesseG=(ticG/990.0)/0.02;
  lcd.setCursor(12,1);
  lcd.print(vitesseG);
  
  // Vitesse roue droite
  vitesseD=(ticD/990.0)/0.02;
  lcd.setCursor(0,1);
  lcd.print(vitesseD);
  
  // Vitesse déplacement
  vit_Depl=((ticD/990.0)*D_Roue*pi)/0.02;
  lcd.setCursor(0,0);
  lcd.print(vit_Depl);
  lcd.setCursor(5,0);

  // Asservissement roue gauche
  erreurG=consigne-vitesseG; //composante P
  sommeEG += erreurG; // composante I
  commandeG=Gmax*erreurG+tauI*sommeEG; // asservissement pi

  // Limitation de la commande entre 0 et 255
  if(commandeG>255)
    commandeG=255;
  else if (commandeG<0)
    commandeG=0;

  // Asservissement roue droite
  erreurD=consigne-vitesseD; //composante P
  sommeED += erreurD; // composante I
  commandeD=Gmax*erreurD+tauI*sommeED; // asservissement pi

  // Limitation de la commande entre 0 et 255
  if(commandeD>255)
    commandeD=255;
  else if (commandeD<0)
    commandeD=0;

  // Application de la commande sur les moteurs
  analogWrite(2,commandeD);
  analogWrite(7,commandeG);

  // Activation des feux stop
  if (vitessePG>vit_Depl+5)
    {
      digitalWrite(ledR_G,HIGH);
      digitalWrite(ledR_M,HIGH);
      digitalWrite(ledR_D,HIGH);
    }
    else
    {
      digitalWrite(ledR_G,LOW);
      digitalWrite(ledR_M,LOW);
      digitalWrite(ledR_D,LOW);
    }
  
  }

}

void avance()
{
 
  // Sens de rotation roue droite
  analogWrite(3,255);
  analogWrite(4,0);
  
  // Sens de rotation roue gauche
  analogWrite(5,255);
  analogWrite(6,0);
  
}

void recule()
{
  // Sens de rotation roue droite
  analogWrite(3,0);
  analogWrite(4,255);
  
  // Sens de rotation roue gauche
  analogWrite(5,0);
  analogWrite(6,255);
}

void gauche()
{
  
  // Sens de rotation roue droite
  analogWrite(3,255);
  analogWrite(4,0);

  // Sens de rotation roue gauche
  analogWrite(5,0);
  analogWrite(6,255);

  // Clignotant gauche
  digitalWrite(ledJ_G,HIGH);
  delay(100);
  digitalWrite(ledJ_G,LOW);
  delay(100);
  
}

void droite()
{

  // Sens de rotation roue droite
  analogWrite(3,0);
  analogWrite(4,255);

  // Sens de rotation roue gauche
  analogWrite(5,255);
  analogWrite(6,0);

  // Clignotant droit
  digitalWrite(ledJ_D,HIGH);
  delay(100);
  digitalWrite(ledJ_D,LOW);
  delay(100);
  
}
void stop()
{
  // Arrêt des moteurs
  analogWrite(2,0);
  analogWrite(7,0);

  // Sens de rotation roue droite
  analogWrite(3,255);
  analogWrite(4,0);
  
  // Sens de rotation roue gauche
  analogWrite(6,0);
  analogWrite(5,255);

  // Allumage des feux stop
  digitalWrite(ledR_G,HIGH);
  digitalWrite(ledR_M,HIGH);
  digitalWrite(ledR_D,HIGH);

}

void clignotantD()
{
  digitalWrite(ledJ_D,HIGH);
  delay(100);
  digitalWrite(ledJ_D,LOW);
  delay(100);
}
void clignotantG()
{
  digitalWrite(ledJ_G,HIGH);
  delay(100);
  digitalWrite(ledJ_G,LOW);
  delay(100);
}

void delais(float a) 
{
  // calcul du temps pour tourner en fonction d'un angle a donné
  temps = (a / (2 * pi * consigne)) * 1000;
  d = roundf(temps)-50;
  delay(d);
}
void loop() 
{ 
  // Calcul de la consigne en fonction de la position du potentiomètre
  tension=(analogRead(3)*5)/1023; 
  consigne=tension*255./5.;
  consigne=consigne*1.21/255; // 1.21 = vitesse max des roues
  
  // Activation des moteurs après appui sur le bouton
  bouton=digitalRead(52);
  if (bouton==0)
  {
    asser=1;
  
    avance();
    delay(3200);
    clignotantG();
    gauche();
    delais(1.4);
    avance();
    delay(5000);
    clignotantG();
    gauche();
    delais(3.3);
    avance();
    delay(1750);
    clignotantD();
    droite();
    delais(0.8);
    avance();
    delay(5300);
    stop();
    
  }
  
  else
  {
    asser=0;
    // Activation des feux stop à la fin de la trajectoire
    delay(1000);
    digitalWrite(ledR_G,LOW);
    digitalWrite(ledR_M,LOW);
    digitalWrite(ledR_D,LOW);

    // Remise à zéro de l'asservissement
    erreurD=0.;
    sommeED =0.;
    commandeD=0;
    erreurG=0.;
    sommeED =0.;
    commandeD=0;
  }
}
