int engelvar  = 11;      //sensör pini
int sayac     = 0;      //ölçüm zaman aralığında kaç geçiş olduğunu tutan sayaç her ölçümde sıfırlanır.
int LED       = 13;
int ornzaman  = 0;      //başlangıç zamanı her ölçüm aralığında bir önceki bitişi başlangıç olarak alır
int rpm;                //4 kanatçık olduğundan sayaç değerinin 4e bölümü devir/dk
#define istnnzmn 60000  //ölçüm için gerekli istenen zaman aralığı RPM -> minute

void setup() {
 
  Serial.begin(9600);
  pinMode(engelvar,INPUT);
  pinMode(LED,OUTPUT);
  engelvar  = 0;
  rpm       = 0;
  ornzaman=millis();
}

void loop() {
  while(millis() - ornzaman < istnnzmn)
  {
    if(engelvar==1)
    {
      sayac++;
      digitalWrite(LED,HIGH);
    }
      digitalWrite(LED,LOW);
  }
  rpm = sayac/4;
  ornzaman = millis();
  Serial.println(sayac);
  Serial.println(rpm);
  sayac = 0;
  rpm = 0;
  
  

}
