// Driver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include "CharacterCreator.h"
#include <ctime>
int main()
{
	BullyBuilder* bulBuild = new BullyBuilder();
	NimbleBuilder* nimBuild = new NimbleBuilder();
	TankBuilder* tankBuild = new TankBuilder();
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
	std::cout << "Charisma: " << *(stats + 5) << "\n\n";
	charCreator.setCharacterBuilder(nimBuild);
	charCreator.createCharacter(1);
	testChar = *charCreator.getCharacter();
	std::cout << "Made a level 1 nimble\n";
	stats = testChar.getAbilityScores();
	std::cout << "Strength: " << *(stats + 0) << "\n";
	std::cout << "Dexterity: " << *(stats + 1) << "\n";
	std::cout << "Constitution: " << *(stats + 2) << "\n";
	std::cout << "Intelligence: " << *(stats + 3) << "\n";
	std::cout << "Wisdom: " << *(stats + 4) << "\n";
	std::cout << "Charisma: " << *(stats + 5) << "\n\n";
	charCreator.setCharacterBuilder(tankBuild);
	charCreator.createCharacter(1);
	testChar = *charCreator.getCharacter();
	std::cout << "Made a level 1 tank\n";
	stats = testChar.getAbilityScores();
	std::cout << "Strength: " << *(stats + 0) << "\n";
	std::cout << "Dexterity: " << *(stats + 1) << "\n";
	std::cout << "Constitution: " << *(stats + 2) << "\n";
	std::cout << "Intelligence: " << *(stats + 3) << "\n";
	std::cout << "Wisdom: " << *(stats + 4) << "\n";
	std::cout << "Charisma: " << *(stats + 5) << "\n\n";
	std::cin >> pause;
}

