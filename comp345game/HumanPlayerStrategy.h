#pragma once
#include "MapUI.h"

class HumanPlayerStrategy : public CharacterStrategy
{
public:
	HumanPlayerStrategy::HumanPlayerStrategy();
	void doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP);
};
