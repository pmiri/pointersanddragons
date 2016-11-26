//! @file 
//! @brief Implementation file for the Map class  
//! The Map class is a type of concrete observable
//!
#pragma once

using namespace std;
#include <list>
#include "Observable.h"
#include "Loggable.h"
#include "Observer.h"
#include "MapObject.h"
#include "Dice.h"

//! Class implementing a game map
class Map : public Observable, public Loggable
{
public:
	//! constants for cell objects
	static char const WALL = 'W';
	static char const CHARACTER = 'P';
	static char const MONSTER = 'M';
	static char const FRIENDLY = 'F';
	static char const TREASURE = 'T';
	static char const BEGIN = 'B';
	static char const END = 'E';

	bool validatePath();
	void fillCell(int x, int y, MapObject obj);
	void PlacePlayer(Character*);
	bool isOccupied(int x, int y);
	void setEntrance(int x, int y);
	void setExit(int x, int y);
	char getCell(int x, int y);
	int getNextMap();

	MapObject getMapObjectAt(int x, int y);

	int PlayerPositionX;
	int PlayerPositionY;

	int BeginPositionX;
	int BeginPositionY;

	int getHeight();
	int getWidth();

	Map();
	Map(int width, int height);
	MapObject **map;
	int nextMap;

	bool mapFinished = false;

	bool moveCharacter(char dir);
	list<MapObject> getListOfMonsterObjs();
	void moveMonster(MapObject monsterMapObject);
};

