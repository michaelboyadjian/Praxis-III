int stepPin = 3; int dirPin = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){ 
    char ch = Serial.read();
    if (ch == 'f'){
      digitalWrite(dirPin,LOW);
      for(int x = 0; x < 20000000; x++){
        analogWrite(stepPin,1000);
        delayMicroseconds(500);
        analogWrite(stepPin,100);
        delayMicroseconds(500);
        char ch1 = Serial.read();
        if (ch1 != 'f') {
          break;
        }
      }
    }
    if (ch == 'b'){
      digitalWrite(dirPin,HIGH);
      for(int x = 0; x < 20000000; x++) {
        analogWrite(stepPin,1000);
        delayMicroseconds(500);
        char ch1 = Serial.read();
        if (ch1 != 'b') {
          break;
        }
      }
    }
    if (ch == 's'){
      digitalWrite(stepPin,LOW);
    }
  }
                 
}
