// Crear un divisor de voltaje con la fotorresistencia
// Colocar la fotorresistencia en la parte inferior
// de forma que la señal sea inversa a la incidencia de luz
#define FOTO A0

// Utilizar un pin con capacidad PWM
#define LED 9

// Factor de conversión entre escala de 10 a 8 bits
// 1024/256 = 1/4
#define FACTOR 0.25

int luz;
int valor;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  luz = analogRead(FOTO);
  valor = round(luz * FACTOR);
  analogWrite(LED, valor);
  Serial.print("Sombra: ");
  Serial.println(luz);
  Serial.print("Valor: ");
  Serial.println(valor);
  delay(500);
}
