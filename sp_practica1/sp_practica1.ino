int conta=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==HIGH){
    delay(100);

    if(digitalRead(2)==LOW){
      conta++;
      Serial.println(conta);
      delay(100);
    }
  }

  if(conta==5){
    digitalWrite(13,HIGH);
  }

  if(conta==8){
    digitalWrite(13,LOW);
    conta=0;
  }

}
