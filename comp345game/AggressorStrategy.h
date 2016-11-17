#pragma once
using namespace std;
#include "MapUI.h"

class AggressorStrategy : public CharacterStrategy
{
public:
	AggressorStrategy::AggressorStrategy();
	void doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP, int* turns, MapObject* monsterMapObj);
};
