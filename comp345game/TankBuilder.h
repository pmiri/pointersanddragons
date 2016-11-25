#pragma once
#include "CharacterBuilder.h"

class TankBuilder : public CharacterBuilder
{
protected:
	void sortAttributes(std::vector<int>* stats);
};