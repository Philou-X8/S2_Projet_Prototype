/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <mmsystem.h>
#include "maploader.h"
#include "mapgrid.h"
#include "gamemanager.h"
#include "menu.h"
//#include "inputmanager.h"

#pragma comment(lib, "Winmm.lib")

using namespace std;

void main() {

	InputManager* inputManager = new InputManager();
	//while(true) cout << inputManager->getInput();
	int bruh = 1;
	while (false) {
		bruh++;
		bruh = bruh % 1000;
		inputManager->updateOutputInfo(bruh, 1);
		Sleep(1000);
	}
	
	MENU menu;
	menu.menu(inputManager);
	//menu.menu;

	int temp;
	cin >> temp;
}

