int motorA1 = 10;
int motorA2 = 9;
int motorB1 = 6;
int motorB2 = 5;
int enaA = 11;
int enaB = 3;
int i=9, gear=2;
char incomingByte;
int fullPower[3] = {50, 100, 255};
int halfPower[3] = {10, 25, 50};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(enaA, OUTPUT);
  pinMode(enaB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if (incomingByte == 'F') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, fullPower[gear]);
       
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else if (incomingByte == 'B') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, fullPower[gear]);

      digitalWrite(motorA2, HIGH);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorB2, HIGH);
      digitalWrite(motorB1, LOW);
      
    }
    else if (incomingByte == 'L') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, fullPower[gear]);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
    }
    else if (incomingByte == 'R') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, fullPower[gear]);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else if (incomingByte == '1' || incomingByte == '2' || incomingByte == '3' ) { gear = 0; }
    else if (incomingByte == '4'|| incomingByte == '5' || incomingByte == '6' ) { gear = 1; }
    else if (incomingByte == '7'|| incomingByte == '8' || incomingByte == '9' ) { gear = 2; }
    else if (incomingByte == 'G') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, halfPower[gear]);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else if (incomingByte == 'J') {
      analogWrite(enaA, halfPower[gear]);
      analogWrite(enaB, fullPower[gear]);

      digitalWrite(motorA2, HIGH);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorB2, HIGH);
      digitalWrite(motorB1, LOW);
    }
    else if (incomingByte == 'H') {
      analogWrite(enaA, fullPower[gear]);
      analogWrite(enaB, halfPower[gear]);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorB2, HIGH);
      digitalWrite(motorB1, LOW); 
    }
    else if (incomingByte == 'I') {
      analogWrite(enaA, halfPower[gear]);
      analogWrite(enaB, fullPower[gear]);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else
    {
      analogWrite(enaA, 190);
      analogWrite(enaB, 190);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
    }
  }
}
