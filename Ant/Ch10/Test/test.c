#include<SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);

int count;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  BTSerial.println(count++);
}
