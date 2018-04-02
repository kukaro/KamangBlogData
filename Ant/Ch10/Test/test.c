int num;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("this number : ");
  Serial.println(num++);
  delay(500);
  while(Serial.available()){
    char ch = Serial.read();
    Serial.println(ch);
  }
}