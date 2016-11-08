//! @file 
//! @brief Implementation file for the MapObject class  
//! The Map Object is anything that exists on a map
//!
#pragma once

using namespace std;
#include "Map.h"
#include "Character.h"
#include "Item.h"
class MapObject
{
public:
	int x, y;
	char getDisplayChar();
	void setCharacter(Character* c);
	void setItem(Item* i);
	Character* getCharacter();
	Item* getItem();
	bool canMove();
	MapObject(int xCoord, int yCoord);
private:
	Character* thisCharacter;
	Item* thisItem;
};
