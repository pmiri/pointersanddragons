#pragma once
#include "CharacterBuilder.h"

class NimbleBuilder : public CharacterBuilder
{
protected:
	void sortAttributes(std::vector<int>* stats);
};