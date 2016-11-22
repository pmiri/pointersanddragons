// Driver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BullyBuilder.h"
#include "CharacterCreator.h"
#include <ctime>
int main()
{
	BullyBuilder* bulBuild = new BullyBuilder();
	string pause;
	CharacterCreator charCreator;
	charCreator.setCharacterBuilder(bulBuild);
	srand(time(NULL));
	charCreator.createCharacter(1);
	Character testChar = *charCreator.getCharacter();
	std::cout << "Made a level 1 bully\n";
	int* stats = testChar.getAbilityScores();
	std::cout << "Strength: " << *(stats + 0) << "\n";
	std::cout << "Dexterity: " << *(stats + 1) << "\n";
	std::cout << "Constitution: " << *(stats + 2) << "\n";
	std::cout << "Intelligence: " << *(stats + 3) << "\n";
	std::cout << "Wisdom: " << *(stats + 4) << "\n";
	std::cout << "Charisma: " << *(stats + 5) << "\n";
	std::cin >> pause;
}

