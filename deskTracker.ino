#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int initialP = 0;
String elapsed = "00:00:00";
int sec = 0;
int _min = 0;
int hour = 0;
int counter = 0;
unsigned long endRun = millis();
unsigned long startStop = 0;
int stopPeriod = 0;
int i = 0, j = 0, afterStop = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  setPins();  
  lcd.init();
  startLCD();
  initialP = analogRead(A0);
}

void loop() {
  // 1. setting distance between device and user
  long pDistance;
  long realDistance = detectDistance();
  int pState = analogRead(A0);
  if (p2cm(initialP) != p2cm(pState)) {
    pDistance = detectP(pState);
  } else {
    pDistance = p2cm(pState);
  }

  // 2. detect elapsed time
  boolean startYN = ledYN(realDistance, pDistance);
  if(startYN) {
    Serial.println("ON");
    stopPeriod += afterStop;
    if(startStop == 0) {
      stopPeriod = 0;
    }
    endRun = millis();
    afterStop = 0;
    elapsed = timeElapse(stopPeriod);
    j = 1;
  } else {
    Serial.println("OFF");
    startStop = millis();
    if(j == 1) {
      stopPeriod += afterStop;
      afterStop = 0;
    } else if (j == 0) {
      afterStop = startStop - endRun;       
    }    
    viewTime(elapsed);
    j = 0;
  }
  
}
