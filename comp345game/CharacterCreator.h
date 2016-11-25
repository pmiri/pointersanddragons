#pragma once
#include "CharacterBuilder.h"

class CharacterCreator
{
public:
	void setCharacterBuilder(CharacterBuilder* cBuilder) { charBuilder = cBuilder; };
	Character* getCharacter() { return charBuilder->getCharacter(); };
	void createCharacter(int level) { charBuilder->buildCharacter(level); };
private:
	CharacterBuilder* charBuilder;
};