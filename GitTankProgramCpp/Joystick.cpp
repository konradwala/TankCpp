#include "Joystick.h"
#include "SerialPort.h"
#include <iostream>


#define DATA_LENGTH 255

Joystick::Joystick()
{
	
	ArduinoJoystick = new SerialPort(portNameJoystick);

}

void Joystick::receivingData()
{
	if (ArduinoJoystick->isConnected())
	{
		ArduinoJoystick->readSerialPort(incomingData, DATA_LENGTH);
		data = incomingData;
		std::cout << data << std::endl;
	}
}

void Joystick::decodingData()
{
	size_t position = data.find('-');
}

void Joystick::execution()
{
	receivingData();
	decodingData();
}

