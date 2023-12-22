String timeElapse(int stopPeriod) {


  String str_hour, str_min, str_sec;

  if (stopPeriod == 0) {
    sec = millis() / 1000 - 60 * counter;
    if(sec >= 60) {
      counter++; 
      _min++;
    }
    if(_min >= 60) {
      _min = 0; 
      hour++;
    }    
  } else {
    sec = millis() / 1000 - 60 * counter - stopPeriod/1000;
    if(sec >= 59) {
      counter++; 
      _min++;
    }
    if(_min >= 59) {
      _min = 0; 
      hour++;
    }
  }


  if(hour<10) {
    str_hour = "0" + String(hour);
  } else {
    str_hour = String(hour);
  }
  if(_min<10) {
    str_min = "0" + String(_min);
  } else {
    str_min = String(_min);
  }
  if(sec<10) {
    str_sec = "0" + String(sec);
  } else {
    str_sec = String(sec);
  }

  elapsed = str_hour + ":" + str_min + ":" + str_sec;

  viewTime(elapsed);
  return elapsed;
}
