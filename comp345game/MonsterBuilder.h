#pragma once
#include "CharacterBuilder.h"

class MonsterBuilder : public CharacterBuilder
{
protected:
	void sortAttributes(std::vector<int>* stats);
};