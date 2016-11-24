#pragma once
#include "CharacterBuilder.h"

class BullyBuilder : public CharacterBuilder
{
protected:
	void sortAttributes(std::vector<int>* stats);
};