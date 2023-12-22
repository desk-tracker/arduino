boolean ledYN(long realDistance, long distance) {
  if (0 <= realDistance && realDistance <= distance) {
    digitalWrite(LED, HIGH);
    return true;
  } else {
    digitalWrite(LED, LOW);
    return false;
  }
}
