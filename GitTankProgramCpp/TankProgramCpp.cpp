#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <regex>


int delayTime = 0;

using namespace std;

const char* portName = "\\\\.\\COM3";

#define MAX_DATA_LENGTH 255

char incomingData[MAX_DATA_LENGTH];

//Control signals for turning on and turning off the led
//Check arduino code
char ledON[] = "ON\n";
char ledOFF[] = "OFF\n";
const char *commandF = "F\n";
const char *commandB = "B\n";

//Arduino SerialPort object
SerialPort* arduino;

//Blinking Delay
const unsigned int BLINKING_DELAY = 1000;

//If you want to send data then define "SEND" else comment it out
#define SEND

void exampleReceiveData(void)
{
	arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
	printf("%s", incomingData);
	Sleep(delayTime);
}

void exampleWriteData(unsigned int delayTime)
{
	arduino->writeSerialPort(ledON, MAX_DATA_LENGTH);
	Sleep(delayTime);
	arduino->writeSerialPort(ledOFF, MAX_DATA_LENGTH);
	Sleep(delayTime);
}

void autoConnect(void)
{
	//better than recusion
	//avoid stack overflows
	while (1) {
		// ui - searching
		std::cout << "Searching in progress";
		// wait connection
		while (!arduino->isConnected()) {
			//Sleep(1000);
			std::cout << ".";
			arduino = new SerialPort(portName);
		}

		//Checking if arduino is connected or not
		if (arduino->isConnected()) {
			std::cout << std::endl << "Connection established at port " << portName << std::endl;
		}

#ifdef SEND
		while (arduino->isConnected()) exampleWriteData(BLINKING_DELAY);
#else // SEND
		while (arduino->isConnected()) exampleReceiveData();
#endif // SEND
	}
}



int main()
{
	arduino = new SerialPort(portName);
	if (arduino->isConnected())
		cout << "Connection Established" << endl;
	else
		cout << "ERROR,check port name ";

	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "TANK TEST");

	while (arduino->isConnected())
	{
		sf::Event event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			arduino->writeSerialPort(ledON, MAX_DATA_LENGTH);
			Sleep(10);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			arduino->writeSerialPort(ledOFF, MAX_DATA_LENGTH);
			Sleep(10);
		
		}
		
		arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
		
		puts(incomingData);

		


		//START SFML 
		

		window.clear(sf::Color::White);
		
		window.display();
		
		//END SFML 

		Sleep(10);

	}
	autoConnect();
}
