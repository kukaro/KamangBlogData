const int pinLED = 3;
const int pinREG = A5;

long val;

void setup() {
  pinMode(pinREG,INPUT);
  pinMode(pinLED,OUTPUT);
}

void loop() {
  val = analogRead(pinREG);
  val = val*255/1023;
  analogWrite(pinLED,val);
}