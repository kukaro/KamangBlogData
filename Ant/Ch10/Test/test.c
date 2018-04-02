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

const int pinBTN = 4;

int val;

void setup() {
  Serial.begin(9600);
  pinMode(pinBTN,INPUT);
}

void loop() {
  val = digitalRead(pinBTN);
  Serial.println(val);
}