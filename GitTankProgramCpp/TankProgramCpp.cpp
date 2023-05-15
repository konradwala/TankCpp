
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "SerialPort.h"
#include "Tank.h"
#include "Joystick.h"
#include "Keyboard.h"
#include "Interface.h"
#include <iostream>





Joystick testObiect;


int main(void){
	{
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "TANK TEST");
		sf::Event event;

		testObiect.execution();
		Sleep(500);

		while (window.pollEvent(event))
		{

		}
		window.clear(sf::Color::White);

		window.display();

		
	}
	
}
