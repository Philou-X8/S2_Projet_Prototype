#include "gamemanager.h"

GameManager::GameManager(InputManager *inManager) {
	inputManager = inManager;
	int map[20][20] = { 0 };
	p1 = new Coords();
	p2 = new Coords();
	Coords mapSize(19, 19);

	cycleCount = 0;

	// load map from file
	mapLoader;
	mapLoader.nextLvl(&map, p1, p2, mapSize);

	// send map to grid object
	mapGrid = MapGrid(p1, p2);
	mapGrid.newGrid(map, mapSize);

	// display grid
	std::cout << mapGrid;

	// initialize some console variables
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	consoleHideCursor(true);

	showLvlProgress();

}

GameManager::GameManager(int niveau, InputManager* inManager) {
	inputManager = inManager;
	int map[20][20] = { 0 };
	p1 = new Coords();
	p2 = new Coords();
	Coords mapSize(19, 19);

	// load map from file
	mapLoader.setLvlProgress(niveau);
	mapLoader.resetLvl(&map, p1, p2, mapSize);

	// send map to grid object
	mapGrid = MapGrid(p1, p2);
	mapGrid.newGrid(map, mapSize);

	// display grid
	std::cout << mapGrid;

	// initialize some console variables
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	consoleHideCursor(true);

	showLvlProgress();
}

GameManager::~GameManager() {
	delete p1;
	delete p2;
}

void GameManager::gameUpdate(char inputKey) {
	cycleCount = (cycleCount + 1) % 5;
	
	inputPlayerAction(inputKey);
	if (levelState()) {
		levelNext();
		showLvlProgress();
	}
	levelUpdateUI();
	
	if (cycleCount == 0) {
		inputManager->updateOutputInfo(
			mapLoader.getLvlProgress(), 
			1
		);

	}

}
void GameManager::inputPlayerAction(char input) {
	switch (input) {
		// ------------------------------- menus
	case 'r':
		levelReload();
		break;
		// ------------------------------- player 1
	case 'w':
		mapGrid.moveP1(Coords(0, 1));	// up
		break;
	case 's':
		mapGrid.moveP1(Coords(0, -1));	// down
		break;
	case 'd':
		mapGrid.moveP1(Coords(1, 0));	// right
		break;
	case 'a':
		mapGrid.moveP1(Coords(-1, 0));	// left
		break;
	case 'f':
		mapGrid.actionRed();
		break;
		// ------------------------------- player 2
	case 'i':
		mapGrid.moveP2(Coords(0, 1));	// up
		break;
	case 'k':
		mapGrid.moveP2(Coords(0, -1));	// down
		break;
	case 'l':
		mapGrid.moveP2(Coords(1, 0));	// right
		break;
	case 'j':
		mapGrid.moveP2(Coords(-1, 0));	// left
		break;
	case 'h':
		mapGrid.actionBlue();
		break;
	default:
		break;
	}
}

bool GameManager::levelState() {
	return mapGrid.mapSolved();
}

void GameManager::levelSet(int lvl) {
	mapLoader.setLvlProgress(lvl);
	int map[20][20] = { 0 };
	Coords mapSize(19, 19);
	mapLoader.resetLvl(&map, p1, p2, mapSize);
	mapGrid.newGrid(map, mapSize);
	consoleHideCursor(true);
}
void GameManager::levelReload() {
	int map[20][20] = { 0 };
	Coords mapSize(19, 19);
	mapLoader.resetLvl(&map, p1, p2, mapSize);
	mapGrid.newGrid(map, mapSize);
	consoleHideCursor(true);
}
void GameManager::levelNext() {
	int map[20][20] = { 0 };
	Coords mapSize(19, 19);
	mapLoader.nextLvl(&map, p1, p2, mapSize);
	mapGrid.newGrid(map, mapSize);
	consoleHideCursor(true);
}
void GameManager::levelUpdateUI() {
	consoleXY(0, 0);
	std::cout << mapGrid;
}

void GameManager::showLvlProgress() {
	consoleXY(0, 22);
	cout << "Current level: (level " << mapLoader.getLvlProgress() << ")";
	consoleXY(0, 0);
}

void GameManager::consoleXY(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(consoleHandle, c);
}
void GameManager::consoleHideCursor(bool hide) {
	cursorInfo.bVisible = !hide;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
