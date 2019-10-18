const int EchoPin = 5;
const int TriggerPin = 6;
const int LedRojo = 9;
const int LedVerde = 10;
const int LedAzul = 11;
float distancia;
long tiempo;

void setup() {
  Serial.begin(9600);
  pinMode(LedRojo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(LedAzul, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {

  digitalWrite(TriggerPin, HIGH);  //se envía un pulso para activar el sensor
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  // medimos el pulso de respuesta
  tiempo = (pulseIn(EchoPin, HIGH) / 2);

  // dividido por 2 por que es el
  // tiempo que el sonido tarda
  // en ir y en volver
  // ahora calcularemos la distancia en cm
  // sabiendo que el espacio es igual a la velocidad por el tiempo
  // y que la velocidad del sonido es de 343m/s y que el tiempo lo
  // tenemos en millonesimas de segundo

  distancia = float(tiempo * 0.0343);

  Serial.print("Distancia: "); // imprime la distancia en el Monitor Serie
  Serial.println(distancia);


  if (distancia >= 40) {
    color(0,255,0); //Verde
  }
  else if ((distancia <= 39) && (distancia >= 20)) {
    color(236,255,0); // "Amarillo"
  }
  else if (distancia <= 19) {
    color(255,0,0); // Rojo
  }

  delay(1000);

}

void color(int rojo,int verde,int azul){
  analogWrite(LedRojo,rojo);
  analogWrite(LedVerde,verde);
  analogWrite(LedAzul,azul);
}
