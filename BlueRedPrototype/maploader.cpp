#include "maploader.h"

MapLoader::MapLoader() {
	lvlPathName = "./levels/level";
	lvlProgress = 0;
	lvlExtension = ".txt";
}
MapLoader::~MapLoader() {

}
bool MapLoader::resetLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2) {
	return loadMap(arr, p1, p2);
}
bool MapLoader::nextLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2) {
	lvlProgress++;
	if (loadMap(arr, p1, p2)) { 
		return true; // loading next level successful 
	}
	else {
		lvlProgress--;
		return false; // loading next level failed 
	}
}
bool MapLoader::loadMap(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2) {
	// genereate the path to the file that must be loaded
	string lvlToLoad = lvlPathName + to_string(lvlProgress) + lvlExtension;
	int buffer;
	rFile.open(lvlToLoad); // open file
	if (rFile.is_open()) {
		for (int y(19); y >= 0; y--) { // print top of grid first
			for (int x(0); x < 20; x++) {
				rFile >> buffer; // read tile from file
				(*arr)[x][y] = buffer; // add tile to map
				// set player to their spawn
				if (buffer == SPAWN1) *p1 = PlayerPos(x, y); 
				if (buffer == SPAWN2) *p2 = PlayerPos(x, y);
			}
		}
		rFile.close();
	}
	else {
		cout << "fuck you you cant code\n";
		return false;
	}
	
	return true;
	
}

void MapLoader::blankMap() {
	ofstream wFile;
	wFile.open("./blankMap.txt");
	if (wFile.is_open()) {
		for (int i(0); i < 20; i++) {
			for (int j(0); j < 20; j++) {
				wFile << "1 ";
			}
			wFile << endl;
		}
		wFile.close();
	}
	else {
		cout << "fuck you you cant code\n";
	}
}