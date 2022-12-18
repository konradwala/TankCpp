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
char commandF[] = "f\n";
char commandB[] = "b\n";

//Arduino SerialPort object
SerialPort* arduino;

//Blinking Delay
const unsigned int BLINKING_DELAY = delayTime;

//If you want to send data then define "SEND" else comment it out
#define SEND

void exampleReceiveData(void)
{
	int readResult = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
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


vector<int> S;
vector<int> J;
vector<int> posOfDash;


int main()
{
	SerialPort arduino(portName);
	if (arduino.isConnected())
		cout << "Connection Established" << endl;
	else
		cout << "ERROR,check port name ";


	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "JOYSTICK TEST");
	//sf::RectangleShape segment(sf::Vector2f(30, 30));

	


	//segment.setPosition(500, 300);
	//segment.setFillColor(sf::Color::Red);

	//string text = "010101110111110000001-12-0-1023-345";

	while (arduino.isConnected())
	{
		sf::Event event;
	//	//START READING DATA

	//	int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
	//	string data;
	//	smatch score;
	//	data = incomingData;
	//	regex pattern("(0|1){21}-\\d+-\\d+-\\d+-\\d+");
	//	//regex_search(data, score, pattern);

	//	if (regex_search(data, score, pattern))
	//	{
	//		data = score[0];
	//		S.clear();
	//		J.clear();
	//		posOfDash.clear();

	//		for (int i = 0; i < 21; i++)
	//		{
	//			string b = data.substr(i, 1);
	//			S.push_back(atoi(b.c_str()));
	//		}

	//		posOfDash.push_back(21);
	//		for (int i = 0; i < 4; i++)
	//		{
	//			posOfDash.push_back(data.find('-', posOfDash[i] + 1));

	//		}
	//		for (int i = 0; i < 4; i++)
	//		{
	//			string help;
	//			help = data.substr(posOfDash[i] + 1, posOfDash[i + 1] - posOfDash[i] - 1);
	//			J.push_back(atoi(help.c_str()));
	//		}

	//		for (int i = 0; i < S.size(); i++)
	//		{
	//			cout << S[i];
	//		}
	//		for (int i = 0; i < 4; i++)
	//		{
	//			cout << "-" << J[i];
	//		}

	//		cout << endl;
	//	}






		//END READING DATA

		//START SENDING DATA


		
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			arduino.writeSerialPort(commandF, MAX_DATA_LENGTH);
			Sleep(50);
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			arduino.writeSerialPort(commandB, MAX_DATA_LENGTH);
			Sleep(50);
		
		}
		
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		string data = incomingData;
		cout << data << endl;
		Sleep(50);
		
		
		//cout << read_result << endl;
		//END SENDING DATA


		//START SFML 

		window.clear(sf::Color::White);
		

		//window.draw(segment);
		window.display();
		//END SFML 

		Sleep(50);

	}
	autoConnect();
}
