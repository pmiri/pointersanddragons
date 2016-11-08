#pragma once
#include "Character.h"
#include "Fighter.cpp"

class CharacterEditor
{
public:
	static Character* createCharacter();
	static Character* editCharacter(Character *ch);
	static Character *loadCharacter(string path);
	static void saveCharacterToFile(string path, Character ch);
};
