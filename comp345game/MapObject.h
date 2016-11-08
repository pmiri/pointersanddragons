//! @file 
//! @brief Implementation file for the MapObject class  
//! The Map Object is anything that exists on a map
//!
#pragma once

using namespace std;
#include "Character.h"
#include "Item.h"
#include <vector>
class MapObject
{
public:
	int x, y;
	char wallOrOtherChar;
	char getDisplayChar();
	void setCharacter(Character* c);
	void setWallOrOtherChar(char ch);
	void setItem(std::vector<Item> i);
	void setXY(int xCor, int yCor);
	Character* getCharacter();
	std::vector<Item> getItems();
	bool canMove();
	MapObject();
	MapObject(int xCoord, int yCoord);
	MapObject(int xCoord, int yCoord, char c);

private:
	Character* thisCharacter;
	std::vector<Item> thisItem;
};
