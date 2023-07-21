int etat=0;
int toto=0;
int etat2=1;
int cle=10;
char chaine;
int buffer=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(24,INPUT_PULLUP);
  pinMode(22,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);

  Serial.begin(9600);
  while (!Serial){}
}

void loop() {
  // put your main code here, to run repeatedly:
  etat=digitalRead(24);
  buffer = Serial.available();
  chaine = Serial.read();

  if (etat2 !=etat){
    if (etat==0)
    { 
      delay(300);
      if(toto==0)
        toto=1;
      else if (toto==1)
        toto=2;
      else if (toto==2)
        toto=3;
      else
        toto=1;
    }
  }
  
  if (toto==1){
    digitalWrite(28,HIGH);
    digitalWrite(26,LOW);
    digitalWrite(22,LOW);

    if (buffer !=0 && chaine!=10)
    {
      delay(15);
      Serial.print(chaine);
    }

  }
  else if (toto==2){
    digitalWrite(28,LOW);
    digitalWrite(22,HIGH);
    digitalWrite(26,LOW);

    if (buffer !=0 && chaine!=10)
    {
      if (chaine+cle<=126)
        chaine=chaine+cle;
      else
        chaine=(chaine+32-126+cle);
      delay(15);
      Serial.print(chaine);
    }
  }
  else if(toto==3){
    digitalWrite(28,LOW);
    digitalWrite(26,HIGH);
    digitalWrite(22,LOW);  
 
    if (buffer !=0 && chaine!=10)
    {
      if (chaine-cle>=33)
        chaine=chaine-cle;
      else
        chaine=(chaine-32+126-cle);
      delay(15); 
      Serial.print(chaine);
    }
  }
  else{
    digitalWrite(28,LOW);
    digitalWrite(26,LOW);
    digitalWrite(22,LOW);
  }
  etat2=etat;
  if (chaine==10)
  Serial.print(chaine);
}
