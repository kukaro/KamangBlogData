
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