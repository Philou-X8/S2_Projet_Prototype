#pragma once

#include <iostream>	// std::cout
#include <thread>	// std::thread
#include <mutex>
#include <list>
#include <queue>

#include <conio.h>

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
	void startThreads();
	void stopThreads();
	void test1();
	void test2(int b);

	void readKeyboard();
	char getInput();

private:
	mutex threadLock;
	thread keyboardComs; // reading from the keyboard
	//thread keyboardAction; // ingame actions from the keyboard
	buttonstates keyboardState;
	buttonstates controllerState;
	queue<char, std::list<char>> pendingInput;
};

