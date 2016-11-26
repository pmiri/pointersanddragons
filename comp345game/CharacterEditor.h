#pragma once
#include "Character.h"
#include "Fighter.cpp"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include "MonsterBuilder.h"
#include "CharacterCreator.h"

class CharacterEditor
{
public:
	static Character* createCharacter();
	static Character* editCharacter(Character *ch);
	static Character *loadCharacter(string path);
	static void saveCharacterToFile(string path, Character ch);
private:
	static int pickStats(std::vector<int> *stats, string stat);
};
