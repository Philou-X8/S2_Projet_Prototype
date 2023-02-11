#include "maploader.h"

MapLoader::MapLoader() {
	filePath = "./levels/level1.txt";
	lvlProgress = 0;
}
MapLoader::~MapLoader() {

}

bool MapLoader::loadMap(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2) {
	lvlProgress++;
	filePath[14] = '0' + lvlProgress;
	int buffer;
	rFile.open(filePath);
	if (rFile.is_open()) {
		for (int y(19); y >= 0; y--) { // print top of grid first
			for (int x(0); x < 20; x++) {
				rFile >> buffer;
				(*arr)[x][y] = buffer;
				if (buffer == SPAWN1) *p1 = PlayerPos(x, y);
				if (buffer == SPAWN2) *p2 = PlayerPos(x, y);
			}
		}
		rFile.close();
	}
	else {
		cout << "fuck you you cant code\n";
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