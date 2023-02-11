/*
* 
*   MAKING A GAME PROTOTYPE FOR SCHOOL
* 
*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "maploader.h"
#include "mapgrid.h"

using namespace std;


void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


void main() {
	
	int map[20][20] = { 0 };
	PlayerPos* p1 = new PlayerPos();
	PlayerPos* p2 = new PlayerPos();
	// load map from file
	MapLoader mapLoader;
	mapLoader.blankMap();
	mapLoader.loadMap(&map, p1, p2);
	// send map to grid object
	MapGrid grid(p1, p2);
	grid.newGrid(map);
	grid.placePlayers(p1, p2);
	// display grid
	std::cout << grid;

	char input = 'a';
	int moveSucess = 0;
	while (input != ' ') {
		input = _getch();
		switch (input) {
			// ------------------------------- player 1
		case 'w':
			grid.moveP1(PlayerPos(0, 1));	// up
			break;
		case 's':
			grid.moveP1(PlayerPos(0, -1));	// down
			break;
		case 'd':
			grid.moveP1(PlayerPos(1, 0));	// right
			break;
		case 'a':
			grid.moveP1(PlayerPos(-1, 0));	// left
			break;
			// ------------------------------- player 2
		case 'i':
			grid.moveP2(PlayerPos(0, 1));	// up
			break;
		case 'k':
			grid.moveP2(PlayerPos(0, -1));	// down
			break;
		case 'l':
			grid.moveP2(PlayerPos(1, 0));	// right
			break;
		case 'j':
			grid.moveP2(PlayerPos(-1, 0));	// left
			break;
		}
		gotoxy(0, 0);
		std::cout << grid;
		if (grid.mapSolved()) {
			mapLoader.loadMap(&map, p1, p2);
			grid.newGrid(map);
			grid.placePlayers(p1, p2);
			gotoxy(0, 0);
			std::cout << grid;
		}
	}
}