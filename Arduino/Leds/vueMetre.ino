float tension=0;
int intervalle=0;
int tab[7]={26,28,30,32,34,36,38};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){}
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(38,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  tension=analogRead(1);
  intervalle=7*tension/1023;
  delay(100);

  for (int i=0;i<=7;++i)
  {
    if(i<=intervalle)
    digitalWrite(tab[i],HIGH);
    else
    digitalWrite(tab[i],LOW);
  }

}