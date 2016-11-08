//! @file 
//! @brief Implementation file for the MapUI class 
//!
#include "MapUI.h"
#include "Map.h"
#include <string>
#include <iostream>
#include <stdlib.h>//for clearning console on windows
using namespace std;

MapUI::MapUI() {
};
MapUI::MapUI(Map* m) {
	_subject = m;
	_subject->Attach(this);
};
void MapUI::Update() {
	PrintMap();
}
string MapUI::getMapString()
{
	return mapString;
}
;
void MapUI::PrintMap() {
	system("cls");
	mapString = "";
	cout << "Map:" << endl;
	int mapHeight = _subject->getHeight();
	int mapWidth = _subject->getWidth();
	for (int h = 0; h < mapHeight; h++) {//for height
		for (int w = 0; w < mapWidth; w++) {//for width
			char cellContent = _subject->getCell(w, h);
			if (cellContent == 'W') {
				mapString += "#";
				continue;
			}
			if (cellContent == 'B') {
				mapString += "B";
				continue;
			}
			if (cellContent == 'E') {
				mapString += "E";
				continue;
			}
			if (cellContent == 'P') {
				mapString += "P";
				continue;
			}
			if (cellContent == 'M') {
				mapString += "M";
				continue;
			}
			if (cellContent == 'F') {
				mapString += "F";
				continue;
			}
			if (cellContent == 'T') {
				mapString += "T";
				continue;
			}
			else {
				mapString += " ";
				continue;
			}
		}
		mapString += "\n";
	}
	cout << mapString << endl << "Press any key to continue";//remove for actual game
};


//int main() {
//	Map* map = new Map(5,5);
//	MapUI* mapUI = new MapUI(map);
//
//	map->setEntrance(0, 0);
//	map->setExit(4, 4);
//
//	map->fillCell(0, 1, MapObject(0, 1, 'W'));
//	getchar();
//	map->fillCell(0, 2, MapObject(0, 2, 'W'));
//	getchar();
//	map->fillCell(0, 3, MapObject(0, 3, 'W'));
//	getchar();
//	map->fillCell(0, 4, MapObject(0, 4, 'W'));
//	getchar();
//	map->fillCell(2, 2, MapObject(2, 2, 'P'));
//	getchar();
//	map->fillCell(3, 3, MapObject(3, 3, 'M'));
//	getchar();
//	map->fillCell(1, 1, MapObject(1, 1, 'T'));
//
//	delete map;
//	delete mapUI;
//
//	getchar();
//
//	return 0;
//}

