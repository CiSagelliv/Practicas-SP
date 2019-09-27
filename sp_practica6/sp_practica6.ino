int buzzer=9;
int tono=0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor=analogRead(tono);
  int frecuencia=map(sensor,0,1023,100,5000);
  int duracion=250;
  tone(buzzer,frecuencia,duracion);
  delay(100);
}
