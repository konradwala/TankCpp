#include <SoftwareSerial.h>

const int dirRight = 2;
const int stepRight = 3;
const int dirLeft = 4;
const int stepLeft = 5;
const int rxPin = 0;
const int txPin = 1;

String command;
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
  if (mySerial.available() > 0){
    command = "";
    command = mySerial.readStringUntil('\n');
    Serial.println(command);
    mySerial.println(command);
    
    //delay(1000);
  }
  
  //voltageValue = map(analogRead(A1), 0 ,1023 , 0, 25);
  
  if(command.equals("F")){
    digitalWrite(dirRight, HIGH);
    digitalWrite(dirLeft, HIGH);

    
    digitalWrite(stepRight, HIGH);
    digitalWrite(stepLeft, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepRight, LOW);
    digitalWrite(stepLeft, LOW);
    delayMicroseconds(1000);
  }

  if(command.equals("B")){
    digitalWrite(dirRight, LOW);
    digitalWrite(dirLeft, LOW);

    digitalWrite(stepRight, HIGH);
    digitalWrite(stepLeft, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepRight, LOW);
    digitalWrite(stepLeft, LOW);
    delayMicroseconds(1000);
  }

  if(command.equals("L")){
    digitalWrite(dirRight, HIGH);
    digitalWrite(dirLeft, LOW);

    digitalWrite(stepRight, HIGH);
    digitalWrite(stepLeft, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepRight, LOW);
    digitalWrite(stepLeft, LOW);
    delayMicroseconds(1000);
  }

  if(command.equals("R")){
    digitalWrite(dirRight, LOW);
    digitalWrite(dirLeft, HIGH);

    digitalWrite(stepRight, HIGH);
    digitalWrite(stepLeft, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepRight, LOW);
    digitalWrite(stepLeft, LOW);
    delayMicroseconds(1000);
  }

  //command = "";

}
