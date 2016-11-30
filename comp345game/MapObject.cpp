#include "MapObject.h"

char MapObject::getDisplayChar()
{
	if (x == 5 && y == 16) {
		char xd = wallOrOtherChar;
	}
	if (thisCharacter != nullptr)
	{
		return thisCharacter->isPlayer;
	}
	else if (wallOrOtherChar == 70) {
		return wallOrOtherChar;
	}
	else if (thisItem.size() >= 1)
	{
		return 'T';
	}
	else
		return wallOrOtherChar;
}

void MapObject::setCharacter(Character * c)
{
	if (c == nullptr) {
		thisCharacter = new Character;//changes the pointer
		thisCharacter = NULL;
		return;
	}
	thisCharacter = c;
	if (wallOrOtherChar != 'F' && wallOrOtherChar != 'E' && wallOrOtherChar != 'B')
		wallOrOtherChar = NULL;
}

void MapObject::setWallOrOtherChar(char ch)
{
	wallOrOtherChar = ch;
}

void MapObject::setItem(std::vector<Item> i)
{
	thisItem = i;
	if (wallOrOtherChar != 'F' && wallOrOtherChar != 'E' && wallOrOtherChar != 'B')
		wallOrOtherChar = NULL;
}

void MapObject::setXY(int xCor, int yCor)
{
	x = xCor;
	y = yCor;
}

Character * MapObject::getCharacter()
{
	return thisCharacter;
}

std::vector<Item> MapObject::getItems()
{
	return thisItem;
}

bool MapObject::canMove()
{
	if (thisCharacter != nullptr)
	{
		if (thisCharacter->isPlayer == 'M')
			return true;
	}
	else
		return false;
}

MapObject::MapObject()
{
	thisCharacter = nullptr;
}

MapObject::MapObject(int xCoord, int yCoord)
{
	thisCharacter = nullptr;
	x = xCoord;
	y = yCoord;
}

//***CAN ONLY BE USED IF char c is NOT a P or M
MapObject::MapObject(int xCoord, int yCoord, char c)
{
	thisCharacter = nullptr;
	wallOrOtherChar = c;
	x = xCoord;
	y = yCoord;
}

void MapObject::replaceMonsterWithTreasure() {
	vector<Item> monsterItems = getCharacter()->wornItems->getItems();
	setItem(monsterItems);
	setCharacter(nullptr);
	thisCharacter = NULL;
	delete thisCharacter;
}