
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SerialPort.h"
#include <iostream>

#define DATA_LENGTH 255

const char* portName = "\\\\.\\COM10";

//Declare a global object
SerialPort* arduino;

//Here '\n' is a delimiter 
const char* commandF = "F\n";
const char* commandB = "B\n";
const char* commandL = "L\n";
const char* commandR = "R\n";
const char* commandN = "N\n";

std::string presentCommand;

char incomingData[MAX_DATA_LENGTH];

int main(void){
	arduino = new SerialPort(portName);
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "TANK TEST");
	

	while (arduino->isConnected())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			arduino->writeSerialPort(commandF, strlen(commandF));
			Sleep(100);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			arduino->writeSerialPort(commandB, strlen(commandB));
			Sleep(100);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			arduino->writeSerialPort(commandN, strlen(commandN));
			Sleep(100);

		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::G)
		{
			std::cout << "pressed" << std::endl;
		}

		arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);

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
