int periode = 1000;
float tension=0;
int rapport=0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    for (int i=0;i<=255;++i)
  {
    delay(5);
    analogWrite(2,valeur+i);
  }
  

  for (int j=254;j>=0;--j)
  {
    delay(5);
    analogWrite(2,valeur+j);
  }




}
