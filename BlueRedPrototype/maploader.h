/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "position.h"

using namespace std;

class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	/*
	bool resetLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2);
	bool nextLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2);
	*/
	bool resetLvl(
		int(*arr)[20][20], 
		Coords* p1, 
		Coords* p2,
		Coords& mapSize
	);
	bool nextLvl(
		int(*arr)[20][20], 
		Coords* p1, 
		Coords* p2,
		Coords& mapSize
	);

	const int getLvlProgress();
	// create a blank map for manual editing
	void blankMap(); 
	void ChoosingLevel(int level);

private:

	bool loadMap(int(*arr)[20][20], Coords* p1, Coords* p2, Coords& mapSize);

	ifstream rFile;
	string lvlPathName;
	int lvlProgress;
	string lvlExtension;
};

