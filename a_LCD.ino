void startLCD() {
  String NAME = "Loveliest";
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello!");
  lcd.setCursor(0,1);
  lcd.print("I\'m " + NAME);
  delay(3000);
}

void LCDPrintRight(String message, int width) {
  int iMax = width - message.length();
  for(int i=0; i<iMax; i++)  {
    message = ' ' + message;
  }
  lcd.print(message);
}

void viewDistance(long realDistance, long pDistance){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("real:");
  LCDPrintRight(String(realDistance) + "cm", 11);
  lcd.setCursor(0,1);
  lcd.print("set:");
  LCDPrintRight(String(pDistance) + "cm", 12);
}

void viewTime(String elapsed) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Elapsed Time:");
  lcd.setCursor(0,1);
  LCDPrintRight(elapsed, 16);
  delay(500);
}
