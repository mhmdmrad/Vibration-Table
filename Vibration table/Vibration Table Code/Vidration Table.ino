const int potPin = A0;  
const int enaPin = 9;   
const int in1Pin = 7;   
const int in2Pin = 8;

void setup() {
  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
}

void loop() {
  int potValue = analogRead(potPin);
  int pwmValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(enaPin, pwmValue);
  delay(10); 
}
