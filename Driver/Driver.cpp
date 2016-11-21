// Driver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BullyBuilder.h"
#include "CharacterCreator.h"

int main()
{
	BullyBuilder* bulBuild = new BullyBuilder();
	CharacterCreator charCreator;
	charCreator.setCharacterBuilder(bulBuild);
	charCreator.createCharacter(1);
	Character testChar = *charCreator.getCharacter();
	bool goodstats = false;
	int* stats = testChar.getAbilityScores();
	int test = *(stats + 1);
}

