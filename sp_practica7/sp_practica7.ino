// Pines del semáforo 1
#define ROJO_1 3
#define AMARILLO_1 4
#define VERDE_1 5

// Pines del semáforo 2
#define ROJO_2 6
#define AMARILLO_2 7
#define VERDE_2 8

#define BOTON 2

bool paso = false;

bool semaforo_0 = true;

void setup() {
  pinMode(ROJO_1, OUTPUT);
  pinMode(AMARILLO_1, OUTPUT);
  pinMode(VERDE_1, OUTPUT);
  pinMode(ROJO_2, OUTPUT);
  pinMode(AMARILLO_2, OUTPUT);
  pinMode(VERDE_2, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BOTON), solicitar_paso, FALLING);
}

void loop() {
  if (paso) {
    rojo_1();
    rojo_2();
    delay(3000);
    paso = false;
  } else {
    if (semaforo_0) {
      rojo_1();
      verde_2();
      delay(2000);
      digitalWrite(VERDE_2, LOW);
      delay(300);
      digitalWrite(VERDE_2, HIGH);
      delay(300);
      digitalWrite(VERDE_2, LOW);
      delay(300);
      digitalWrite(VERDE_2, HIGH);
      delay(300);
      digitalWrite(VERDE_2, LOW);
      delay(300);
      digitalWrite(VERDE_2, HIGH);
      delay(300);
      amarillo_2();
      delay(2000);
    } else {
      verde_1();
      rojo_2();
      delay(2000);
      digitalWrite(VERDE_1, LOW);
      delay(300);
      digitalWrite(VERDE_1, HIGH);
      delay(300);
      digitalWrite(VERDE_1, LOW);
      delay(300);
      digitalWrite(VERDE_1, HIGH);
      delay(300);
      digitalWrite(VERDE_1, LOW);
      delay(300);
      digitalWrite(VERDE_1, HIGH);
      delay(300);
      amarillo_1();
      delay(2000);
    }
    semaforo_0 = !semaforo_0;
  }
}

void solicitar_paso() {
  paso = true;
}

void rojo_1() {
  digitalWrite(ROJO_1, HIGH);
  digitalWrite(AMARILLO_1, LOW);
  digitalWrite(VERDE_1, LOW);
}
void amarillo_1() {
  digitalWrite(ROJO_1, LOW);
  digitalWrite(AMARILLO_1, HIGH);
  digitalWrite(VERDE_1, LOW);
}
void verde_1() {
  digitalWrite(ROJO_1, LOW);
  digitalWrite(AMARILLO_1, LOW);
  digitalWrite(VERDE_1, HIGH);
}
void rojo_2() {
  digitalWrite(ROJO_2, HIGH);
  digitalWrite(AMARILLO_2, LOW);
  digitalWrite(VERDE_2, LOW);
}
void amarillo_2() {
  digitalWrite(ROJO_2, LOW);
  digitalWrite(AMARILLO_2, HIGH);
  digitalWrite(VERDE_2, LOW);
}
void verde_2() {
  digitalWrite(ROJO_2, LOW);
  digitalWrite(AMARILLO_2, LOW);
  digitalWrite(VERDE_2, HIGH);
}
