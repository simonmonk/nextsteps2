// sketch_08_01_binary

void setup() {
  Serial.begin(9600);
  byte a = B00010001; // 17
  byte b = B00011001; // 25
  byte result = a + b;
  Serial.println(result, 2); // binary
  Serial.println(result, 16); // hex
  Serial.println(result, 10); // decimal
}

void loop() {
}
