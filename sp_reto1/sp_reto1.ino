// Pines de los leds
#define LED_1 2
#define LED_2 3

// Frecuencia definida en Hertz
#define frequency_1 2
#define frequency_2 5

// Intervalo = 1/frecuencia
// Expresado en milisegundos
const unsigned long interval_1 = round(1000 / frequency_1);
const unsigned long interval_2 = round(1000 / frequency_2);

// Variables globales para mantener el control del tiempo transcurrido
unsigned long previous_1 = 0;
unsigned long previous_2 = 0;
unsigned long current = 0;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() {
  current = millis();
  if (current - previous_1 == interval_1) {
    // Si el intervalo transcurrido desde el último instante coincide
    previous_1 = current;                     // Guardar el último instante
    digitalWrite(LED_1, !digitalRead(LED_1)); // Alternar el valor del led
  }
  if (current - previous_2 == interval_2) {
    previous_2 = current;
    digitalWrite(LED_2, !digitalRead(LED_2));
  }
  // Es posible agregar más leds de ser necesario
  // if (current - previous_3 == interval_3 ...
}
