#include <Arduino.h>

#define LedGreen 12

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LedGreen, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  char readSerial = Serial.read();
  
  if(readSerial == '1'){
    digitalWrite(LedGreen, HIGH);
  }
  else if(readSerial == '0'){
    digitalWrite(LedGreen, LOW);
  }
}
