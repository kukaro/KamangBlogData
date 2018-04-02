int num;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("this number : ");
  Serial.println(++num);
  delay(500);
  if(Serial.available()){
    Serial.print("input data :");
    Serial.println(Serial.available());
  }
}