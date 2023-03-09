#pragma once

#include <iostream>	// std::cout
#include <string>
#include <thread>	// std::thread
#include <mutex>
#include <list>
#include <queue>

#include <conio.h>

#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message


using namespace std;

#define ACTIVE 1
#define ARMED 0

struct buttonstates {
	bool up = ARMED;
	bool down = ARMED;
	bool right = ARMED;
	bool left = ARMED;
	bool action = ARMED;
	bool reload = ARMED;
	bool menu = ARMED;
};

SerialPort* arduino; //doit etre un objet global!

class InputManager
{
public:
	InputManager();
	~InputManager();
	void startThreads();
	void stopThreads();

	void readKeyboard(); // looping thread
	void readController(); // looping thread
	char getInput();


private:
	mutex threadLock;
	thread keyboardComs; // reading from the keyboard
	//thread keyboardAction; // ingame actions from the keyboard
	buttonstates keyboardState;
	buttonstates controllerState;
	queue<char, std::list<char>> pendingInput;

	json comsIn;
	json comsOut;
	bool recieveComs();
};

