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
		return ' ';
}

void MapObject::setCharacter(Character * c)
{
	thisCharacter = c;
}

void MapObject::setItem(std::vector<Item> i)
{
	thisItem = i;
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

MapObject::MapObject(int xCoord, int yCoord)
{
	x = xCoord;
	y = yCoord;
}
