#pragma once
#include "Character.h"
#include "Fighter.cpp"

class CharacterEditor
{
public:
	static void createCharacter();
	static void editCharacter();
	static Character *loadCharacter(string path);
};
