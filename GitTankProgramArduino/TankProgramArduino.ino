#include <SoftwareSerial.h>

const unsigned int MAX_MESSAGE_LENGTH = 12;

const int dirRight = 2;
const int stepRight = 3;
const int dirLeft = 4;
const int stepLeft = 5;
const int rxPin = 10;
const int txPin = 11;

String command;
int secondCommand = "";
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
  
  while (Serial.available() > 0){
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;
    char inByte = Serial.read();

  
    if ( inByte != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1) ){
      message[message_pos] = inByte;
      message_pos++;
    }
    else{
      message[message_pos] = '\n';
      message_pos = 0;
      mySerial.print(message);
      Serial.print(message);
    }
  }

  
  
  
  
  //voltageValue = map(analogRead(A1), 0 ,1023 , 0, 25);
  


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
