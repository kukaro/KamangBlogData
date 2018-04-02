const int pinLED = 5;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);

}

void loop() {
  for(int i=0;i<256;i++){
    analogWrite(pinLED,i);
    delay(5);
  }
  for(int i=255;i>=0;i--){
    analogWrite(pinLED,i);
    delay(5);
  }
}