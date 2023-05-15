#define DATA_LENGTH 255
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Tank.h"
#include "SerialPort.h"
#include <iostream>

Tank::Tank()
{
	ArduinoTank = new SerialPort(portNameTank);
}

void Tank::sendingData()
{
	ArduinoTank->writeSerialPort(command, strlen(command));
}

void Tank::receivingData()
{
	ArduinoTank->readSerialPort(incomingData, DATA_LENGTH);
}

void Tank::execution()
{
	sendingData();
}