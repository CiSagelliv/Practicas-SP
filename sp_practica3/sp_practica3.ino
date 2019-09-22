#define LED 13

// Conectar el interruptor magnético
// directamente a tierra en un extremo
// y el otro extremo al pin indicado
#define CONTACTO 2

void setup() {
  pinMode(CONTACTO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (!digitalRead(CONTACTO)) {
    for (int i = 0; i < 50; i++) {
      digitalWrite(LED, HIGH);
      delay(50);
      digitalWrite(LED, LOW);
      delay(50);
    }
  }
}
