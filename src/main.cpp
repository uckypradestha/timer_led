#include <Arduino.h>
#include <TimerOne.h>

void longBlink() {
  digitalWrite(11, !digitalRead(11));
}
void setup() {
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  
  Timer1.initialize(5000000);    
  Timer1.attachInterrupt(longBlink);  
}

void loop() {
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(500);
}