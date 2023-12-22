long detectP(int pState) {
  unsigned long time_previous = millis();
  long pDistance;

  pDistance = detectVariation(pState, time_previous);
  return pDistance;
}

long detectVariation(int pState, unsigned long time_previous) {
  unsigned long time_current = millis();  
  unsigned long elapsed = time_current - time_previous;
  
  long realDistance = detectDistance();
  long pDistance = p2cm(pState);
  viewDistance(realDistance, pDistance);  
  ledYN(realDistance, pDistance);

  if(elapsed < 3000) {
    if(pState != initialP) {
      initialP = pState;
      pState = analogRead(A0);
      time_previous = millis();
    }
    delay(100);
    detectVariation(pState, time_previous);
  } else {
    initialP = pState;
    return pDistance;
  } 
}

long p2cm(int pState) {
  long pDistance = map(pState, 0, 1023, 0, 200);
  return pDistance;
}
