#pragma once
using namespace std;
#include "MapUI.h"

class HumanPlayerStrategy : public CharacterStrategy
{
public:
	HumanPlayerStrategy::HumanPlayerStrategy();
	void doStrategy(char in, Map* mapP, int* turns, MapObject* monsterMapObj = NULL);
private:
	bool sinventoryMode;
	bool splayerMode;
};
