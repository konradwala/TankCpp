#include <SoftwareSerial.h>

const int dirRight = 2;
const int stepRight = 3;
const int dirLeft = 4;
const int stepLeft = 5;
const int rxPin = 10;
const int txPin = 11;

String command = "";
float voltageValue = 0;

SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  pinMode(dirRight,OUTPUT);
  pinMode(stepRight,OUTPUT);
  pinMode(dirLeft,OUTPUT);
  pinMode(stepLeft,OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    command = Serial.readStringUntil('\n');
    mySerial.print(command);
    Serial.print(command);
  }

  
  
  
  //voltageValue = map(analogRead(A1), 0 ,1023 , 0, 25);
  //mySerial.println("dupa");


  if(command.equals("f")){
    digitalWrite(dirRight, HIGH);
    digitalWrite(dirLeft, HIGH);

    for(int i=0; i<1000; i++){
      digitalWrite(stepRight, HIGH);
      digitalWrite(stepLeft, HIGH);
      delayMicroseconds(1000);

      digitalWrite(stepRight, LOW);
      digitalWrite(stepLeft, LOW);
      delayMicroseconds(1000);
    }
  }

  if(command.equals("b")){
    digitalWrite(dirRight, LOW);
    digitalWrite(dirLeft, LOW);

    digitalWrite(stepRight, HIGH);
    digitalWrite(stepLeft, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepRight, LOW);
    digitalWrite(stepLeft, LOW);
    delayMicroseconds(1000);
  }

}
