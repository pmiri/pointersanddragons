﻿//! @file 
//! @brief Implementation file for the MapUI class 
//!
#include "MapUI.h"
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

MapUI::~MapUI() {
	_subject->Detach(this);
}

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
			}
			else if (cellContent == 'B') {
				mapString += "B";
			}
			else if (cellContent == 'E') {
				mapString += "E";
			}
			else if (cellContent == 'P') {
				mapString += "P";
			}
			else if (cellContent == 'M') {
				//check if monster is dead
				Character* monster = _subject->getMapObjectAt(w, h).getCharacter();
				if (monster->getHitPoints() <= 0) {
					//check if monster has items
					vector<Item> allMonsterItems = monster->wornItems->getItems();
					vector<Item> validMonsterItems = vector<Item>();
					for each (Item itm in allMonsterItems)
					{
						if (itm.getType() != "")
							validMonsterItems.push_back(itm);
					}
					if (monster->wornItems != NULL && validMonsterItems.size() > 0) {
						//ItemContainer droppedTreasure = ItemContainer(monster->wornItems->getItems());
						_subject->getMapObjectAt(w, h).replaceMonsterWithTreasure();

						MapObject* nmo = new MapObject;
						nmo->setItem(validMonsterItems);
						_subject->setMapObjectAt(w, h, nmo);

						//_subject->getMapObjectAt(w, h).setItem(monsterItems);
						//_subject->getMapObjectAt(w, h).setCharacter(nullptr);

						//_subject->setMapObjectAt(w, h, new MapObject);
						//_subject->getMapObjectAt(w, h).setItem(droppedTreasure.getItems());
						//_subject->getMapObjectAt(w, h).setCharacter(nullptr);//there might be a problem here
						//mapString += "T";
						w--;
						continue;
					}
					_subject->setMapObjectAt(w, h, new MapObject);
					mapString += " ";
				}
				else {
					mapString += "M";
				}
			}
			else if (cellContent == 'F') {
				mapString += "F";
			}
			else if (cellContent == 'T') {
				mapString += "T";
			}
			else {
				mapString += " ";
			}
			mapString += " ";
		}
		mapString += "\n";
	}
	cout << mapString << endl;//<< "Press any key to continue";//remove for actual game
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
