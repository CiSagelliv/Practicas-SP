const int forward_led = 3;
const int backward_led = 2;
const int photo_1 = 5;
const int photo_2 = 6;

int state = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(forward_led, OUTPUT);
  pinMode(backward_led, OUTPUT);
  pinMode(photo_1, INPUT_PULLUP);
  pinMode(photo_2, INPUT_PULLUP);
}

void loop() {
  switch (state) {
    case -3:
      if (C()) {
        ++state;
      } else if (A()) {
        backward();
        state = 0;
      }
      break;
    case -2:
      if (D()) {
        ++state;
      } else if (B()) {
        --state;
      }
      break;
    case -1:
      if (A()) {
        ++state;
      } else if (C()) {
        --state;
      }
      break;
    case 0:
      if (B()) {
        ++state;
      } else if (D()) {
        --state;
      }
      break;
    case 1:
      if (C()) {
        ++state;
      } else if (A()) {
        --state;
      }
      break;
    case 2:
      if (D()) {
        ++state;
      } else if (B()) {
        --state;
      }
      break;
    case 3:
      if (A()) {
        forward();
        state = 0;
      } else if (C()) {
        --state;
      }
      break;

  }
}

bool A() {
  return digitalRead(photo_1) && digitalRead(photo_2);
}

bool B() {
  return !digitalRead(photo_1) && digitalRead(photo_2);
}

bool C() {
  return !digitalRead(photo_1) && !digitalRead(photo_2);
}

bool D() {
  return digitalRead(photo_1) && !digitalRead(photo_2);
}

void forward() {
  ++count;
  print_count();
  digitalWrite(forward_led, HIGH);
  delay(100);
  digitalWrite(forward_led, LOW);
}

void backward() {
  --count;
  print_count();
  digitalWrite(backward_led, HIGH);
  delay(100);
  digitalWrite(backward_led, LOW);
}

void print_count() {
  Serial.print("Conteo: ");
  Serial.println(count);
}
