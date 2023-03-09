/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "inputmanager.h"

using namespace std;

class MENU
{
public:

	void menu(InputManager* inMng);
	void mainMenu();
	void optionsMenu();
	void options();

private:

	int choice1 = 0;
	int choice2 = 3;

	InputManager* inputManager;

};