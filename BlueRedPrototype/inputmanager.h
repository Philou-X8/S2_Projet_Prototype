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



class InputManager
{
public:
	InputManager();
	~InputManager();

	char getInput();

	void startThreads();
	bool stopThreads();

private:
	mutex threadLock;
	thread keyboardComs; // reading from the keyboard
	thread controllerComs; // reading from the controller
	void readKeyboard(); // looping thread
	void readController(); // looping thread
	bool isActiveKeyboard; // should keep the threads running
	bool isActiveController; // should keep the threads running
	
	buttonstates keyboardState;
	buttonstates controllerState;
	queue<char, std::list<char>> pendingInput;

	json comsIn;
	json comsOut;
	bool recieveComs();
	std::list<char> decodeController();

};

