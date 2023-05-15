#ifndef Tank_h
#define Tank_h
#define MAX_DATA_LENGTH 255
#include "SerialPort.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Tank
{
public:
	SerialPort* ArduinoTank;
	const char* portNameTank = "\\\\.\\COM5";

	Tank();
	void sendingData();
	void receivingData();
	void execution();

	const char* command;

	char incomingData[MAX_DATA_LENGTH];

};

#endif