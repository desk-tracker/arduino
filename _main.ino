#define TRIG 7
#define ECHO 6
#define LED 8

void setPins() {
  // ultrasonic
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  
}
