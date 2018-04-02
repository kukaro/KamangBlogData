

const int pinLED = 2;
bool sw = false;
char tmp = 'A';

void setup() {
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);

}

void loop() {
  digitalWrite(pinLED,sw);
  if(Serial.available()){
    Serial.read();
    sw=!sw;
  }
}