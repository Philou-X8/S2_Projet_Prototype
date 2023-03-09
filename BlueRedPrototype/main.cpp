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
	MENU menu;
	menu.menu(inputManager);
	//menu.menu;

}

