#ifndef Joystick_h
#define Joystick_h
#define MAX_DATA_LENGTH 255
#include "SerialPort.h"
#include <iostream>


class Joystick 
{
public:
	SerialPort* ArduinoJoystick;
	const char* portNameJoystick = "\\\\.\\COM8";
	char incomingData[MAX_DATA_LENGTH];
	std::string data;

	Joystick();
	void receivingData();
	void decodingData();
	void execution();

	int axisOneX;
	int axisOneY;
	int axisTwoX;
	int axisTwoY;

	bool switchOne;
	bool switchTwo;
	bool switchThree;
	bool switchBrake;
	bool switchTriggerFirst;
	bool switchTriggerSecond;

	bool crossOneU;
	bool crossOneD;
	bool crossOneR;
	bool crossOneL;
	bool crossOneC;

	bool crossTwoU;
	bool crossTwoD;
	bool crossTwoR;
	bool crossTwoL;
	
	bool crossThreeU;
	bool crossThreeD;
	bool crossThreeR;
	bool crossThreeL;

};

#endif
