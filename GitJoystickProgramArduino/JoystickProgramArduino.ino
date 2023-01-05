#include <pcf8574.h>

PCF8574 ex1(0x20);

String command = "";

void setup() {
  Serial.begin(9600);

  for(int i=0; i<14; i++)
  {
    pinMode(i,INPUT_PULLUP);
  }

  for(int i=0; i<8; i++)
  {
    pinMode(ex1, i, INPUT_PULLUP);
  }
}

void loop() {
  command = "";

 //if(digitalRead(ex1,0)==LOW)
  //{Serial.println("1");}

  for(int i=0; i<14; i++)
  {
    if(i!=1)
    {
      if(digitalRead(i) == LOW)
      {
        command = command + "1";
      }else{
        command = command + "0";
      }
    }
    
  }

  for(int i=0; i<8; i++)
  {
    if(digitalRead(ex1,i)==LOW)
    {
      command = command + "1";
    }else{
      command = command + "0";
    }
  }

  command = command + "-";
  command = command + analogRead(A0);
  command = command + "-";
  command = command + analogRead(A1);
  command = command + "-";
  command = command + analogRead(A2);
  command = command + "-";
  command = command + analogRead(A3);

  Serial.println(command);

}
