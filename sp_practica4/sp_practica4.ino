
int ledRojo = 9;
int ledVerde=10;
int ledAzul=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  color(255,0,0); // Rojo
  delay(1000);
  color(0,255,0); // Verde
  delay(1000);
  color(0,0,255); // Azul
  delay(1000);
  color(0,238,255); // "Cyan"
  delay(1000); 
  color(171,0,255); // "Morado"
  delay(1000);
  color(236,255,0); // "Amarillo"
  delay(1000);
}

void color(int rojo,int verde,int azul){
  analogWrite(ledRojo,rojo);
  analogWrite(ledVerde,verde);
  analogWrite(ledAzul,azul);
}
