#include "MapObject.h"

char MapObject::getDisplayChar()
{
	if (thisCharacter != nullptr)
	{
		return thisCharacter->isPlayer;
	}
	else if (thisItem.size() > 1)
	{
		return 'T';
	}
	else
		return wallOrOtherChar;
}

void MapObject::setCharacter(Character * c)
{
	thisCharacter = c;
	wallOrOtherChar = NULL;
}

void MapObject::setWallOrOtherChar(char ch)
{
	wallOrOtherChar = ch;
}

void MapObject::setItem(std::vector<Item> i)
{
	thisItem = i;
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
