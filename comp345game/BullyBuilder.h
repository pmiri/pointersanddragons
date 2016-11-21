#pragma once
#include "CharacterBuilder.h"

class BullyBuilder : public CharacterBuilder
{
public:
	BullyBuilder();
protected:
	void sortAttributes(std::vector<int>* stats);
};