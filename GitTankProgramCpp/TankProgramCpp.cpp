
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SerialPort.h"
#include "Tank.h"
#include "Joystick.h"
#include <iostream>

#define DATA_LENGTH 255

const char* portNameTank = "\\\\.\\COM5";


//Declare a global object
SerialPort* ArduinoTank;
Joystick testObiect;

//Here '\n' is a delimiter 
const char* commandF = "F\n";
const char* commandB = "B\n";
const char* commandL = "L\n";
const char* commandR = "R\n";
const char* commandN = "N\n";

std::string presentCommand;

char incomingData[MAX_DATA_LENGTH];

int main(void){
	ArduinoTank = new SerialPort(portNameTank);
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "TANK TEST");
	

	while (ArduinoTank->isConnected())
	{
		sf::Event event;

		testObiect.execution();
		Sleep(500);

		while (window.pollEvent(event))
		{
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&presentCommand!="forward")
		{
			ArduinoTank->writeSerialPort(commandF, strlen(commandF));
			presentCommand = "forward";
			Sleep(100);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && presentCommand != "backward")
		{
			ArduinoTank->writeSerialPort(commandB, strlen(commandB));
			presentCommand = "backward";
			Sleep(100);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && presentCommand != "right")
		{
			ArduinoTank->writeSerialPort(commandR, strlen(commandR));
			presentCommand = "right";
			Sleep(100);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && presentCommand != "left")
		{
			ArduinoTank->writeSerialPort(commandL, strlen(commandL));
			presentCommand = "left";
			Sleep(100);

		}

		if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Up||
			event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Left ||
			event.key.code == sf::Keyboard::Right ))
		{
			ArduinoTank->writeSerialPort(commandN, strlen(commandN));
			presentCommand = "nothing";
		}

		ArduinoTank->readSerialPort(incomingData, DATA_LENGTH);

		//puts(incomingData);

		std::cout << incomingData << std::endl;


		//START SFML 


		

		//END SFML 

		//Sleep(100);


		}
		window.clear(sf::Color::White);

		window.display();

		
	}
	
}
