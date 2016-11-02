﻿//! @file 
//! @brief Implementation file for the MapUI class 
//!
#include "MapUI.h"
#include "Map.h"
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
};
void MapUI::PrintMap() {
	system("cls");
	cout << "Map:" << endl;
	int mapHeight = _subject->getHeight();
	int mapWidth = _subject->getWidth();
	for (int h = 0; h < mapHeight; h++) {//for height
		for (int w = 0; w < mapWidth; w++) {//for width
			char cellContent = _subject->getCell(w, h);
			if (cellContent == 'W') {
				cout << "#";
				continue;
			}
			if (cellContent == 'B' || cellContent == 'E') {
				cout << "H";
				continue;
			}
			if (cellContent == 'C') {
				cout << "I";
				continue;
			}
			if (cellContent == 'M') {
				cout << "M";
				continue;
			}
			if (cellContent == 'T') {
				cout << "T";
				continue;
			}
			else {
				cout << " ";
				continue;
			}
		}
		cout << endl;
	}
	cout << endl << "Press any key to continue";//remove for actual game
};


int main() {
	Map* map = new Map(5,5);
	MapUI* mapUI = new MapUI(map);

	map->setEntrance(0, 0);
	map->setExit(4, 4);

	map->fillCell(0, 1, 'W');
	
	getchar();
	map->fillCell(0, 2, 'W');
	getchar();
	map->fillCell(0, 3, 'W');
	getchar();
	map->fillCell(0, 4, 'W');
	getchar();
	map->fillCell(1, 4, 'W');
	getchar();
	map->fillCell(2, 4, 'W');
	getchar();
	map->fillCell(3, 4, 'W');
	getchar();
	map->fillCell(4, 3, 'W');
	getchar();
	map->fillCell(4, 2, 'W');
	getchar();
	map->fillCell(4, 1, 'W');
	getchar();
	map->fillCell(4, 0, 'W');
	getchar();
	map->fillCell(3, 0, 'W');
	getchar();
	map->fillCell(2, 0, 'W');
	getchar();
	map->fillCell(1, 0, 'W');
	getchar();
	map->fillCell(2, 2, 'C');
	getchar();
	map->fillCell(3, 3, 'M');
	getchar();
	map->fillCell(1, 1, 'T');

	delete map;
	delete mapUI;

	getchar();

	return 0;
}

