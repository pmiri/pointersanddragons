//! @file 
//! @brief Implementation file for the MapObject class  
//! The Map Object is anything that exists on a map
//!
#pragma once

using namespace std;
#include "Map.h"
#include "Character.h"
#include "Item.h"
#include <vector>
class MapObject
{
public:
	int x, y;
	char getDisplayChar();
	void setCharacter(Character* c);
	void setItem(std::vector<Item> i);
	Character* getCharacter();
	std::vector<Item> getItems();
	bool canMove();
	MapObject(int xCoord, int yCoord);
private:
	Character* thisCharacter;
	std::vector<Item> thisItem;
};
