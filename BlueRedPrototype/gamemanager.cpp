#include "gamemanager.h"

GameManager::GameManager() {
	int map[20][20] = { 0 };
	p1 = new PlayerPos();
	p2 = new PlayerPos();
	// load map from file
	mapLoader;
	mapLoader.nextLvl(&map, p1, p2);
	// send map to grid object
	grid = MapGrid(p1, p2);
	grid.newGrid(map);
	grid.placePlayers(p1, p2);
	// display grid
	std::cout << grid;

	// initialize some console variables
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(consoleHandle, cursorInfo);
}

void GameManager::levelReload() {
	int map[20][20] = { 0 };
	mapLoader.resetLvl(&map, p1, p2);
	grid.newGrid(map);
	grid.placePlayers(p1, p2);
}
void GameManager::levelNext() {
	int map[20][20] = { 0 };
	mapLoader.nextLvl(&map, p1, p2);
	grid.newGrid(map);
	grid.placePlayers(p1, p2);
}
void GameManager::levelUpdateUI() {
	consoleXY(0, 0);
	std::cout << grid;
}
bool GameManager::levelState() {
	return grid.mapSolved();
}

void GameManager::inputManager(char input) {
	switch (input)
	{
	case 'r':
		inputMapAction(input);
		break;
	case 'w':
	case 's':
	case 'd':
	case 'a':
	case 'i':
	case 'k':
	case 'l':
	case 'j':
		inputPlayerAction(input);
		break;
	default:
		break;
	}
}

void GameManager::inputMapAction(char input) {
	switch (input)
	{
	case 'r':
		levelReload();
		levelUpdateUI();
		break;
	default:
		break;
	}
}

void GameManager::inputMenuAction(char input) {

}

void GameManager::inputPlayerAction(char input) {
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
}

void GameManager::consoleXY(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(consoleHandle, c);
}
void GameManager::consoleHideCursor(bool hide) {
	cursorInfo->bVisible = !hide;
	SetConsoleCursorInfo(consoleHandle, cursorInfo);
}