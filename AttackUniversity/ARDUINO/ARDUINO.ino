void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
          digitalWrite(2, HIGH);

          pinMode(3, INPUT);
          digitalWrite(3, HIGH);
          pinMode(4, INPUT);
          digitalWrite(4, HIGH);
          pinMode(5, INPUT);
          digitalWrite(5, HIGH);
          pinMode(6, INPUT);
          digitalWrite(6, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(2))Serial.print(" ");
  else if (!digitalRead(3))Serial.print("D");
  else if (!digitalRead(4))Serial.print("W");
  else if (!digitalRead(5))Serial.print("S");
  else if (!digitalRead(6))Serial.print("A");
  else Serial.print("N");
  delay(50);

}
