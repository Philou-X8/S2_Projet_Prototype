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
		PlayerPos* p1, 
		PlayerPos* p2,
		PlayerPos& mapSize
	);
	bool nextLvl(
		int(*arr)[20][20], 
		PlayerPos* p1, 
		PlayerPos* p2,
		PlayerPos& mapSize
	);

	const int getLvlProgress();
	// create a blank map for manual editing
	void blankMap(); 

private:

	bool loadMap(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2, PlayerPos& mapSize);

	ifstream rFile;
	string lvlPathName;
	int lvlProgress;
	string lvlExtension;
};

