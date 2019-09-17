#define frequency_1 2
#define frequency_2 5
unsigned long interval_1 = round(1000 / frequency_1);
unsigned long interval_2 = round(1000 / frequency_2);

unsigned long previous_1 = 0;
unsigned long previous_2 = 0;
unsigned long current = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  current = millis();
  if (current - previous_1 == interval_1) {
    previous_1 = current;
    digitalWrite(2, !digitalRead(2));
  }
  if (current - previous_2 == interval_2) {
    previous_2 = current;
    digitalWrite(3, !digitalRead(3));
  }
}
