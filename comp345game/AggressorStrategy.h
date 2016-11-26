#pragma once
using namespace std;
#include "MapUI.h"

class AggressorStrategy : public CharacterStrategy
{
public:
	AggressorStrategy::AggressorStrategy();
	void doStrategy(char in, Map* mapP, int* turns, MapObject* monsterMapObj = NULL);
};
