//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include<iostream>
#include <conio.h>

class MapObject;//forward declaration to help compilation

inline char characterKeyPress() {
	int i = _getche();
	char input = static_cast<char>(i);
	cout << endl;
	return input;
}

//! Constructor: creates character with random ability scores 
Character::Character()
{
	isPlayer = 'P';
	//seed random number generator
	srand(time(0));

	//characters start with a pool of ability points
	int abilityPool = 42;

	//distribute the points randomly
	abilityScores[0] = 3;
	abilityScores[1] = 3;
	abilityScores[2] = 3;
	abilityScores[3] = 3;
	abilityScores[4] = 3;
	abilityScores[5] = 3;
	for (int i = 0; i < 6; i++)
	{
		abilityBonuses[i] = 0;
	}
	while (abilityPool != 0)
	{
		int i = rand() % 6;
		//check if the selected ability is already maxed out, skip to the next if so 
		//note that this maximum valueonly applies when initially creating a character
		while (abilityScores[i] + 1 >= 19)
			i = (i + 1) % 6;
		abilityScores[i]++;
		abilityPool--;
	}

	//default hit points is 10
	maxHitPoints = 10;
	initAbilityModifiers();
	currentHitPoints = maxHitPoints;
	baseAttackBonus = 1;
	level = 1;
}

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha, char isP)
{
	isPlayer = isP;
	abilityScores[0] = str;
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;
	for (int i = 0; i < 6; i++)
	{
		abilityBonuses[i] = 0;
	}
	//default hit points is 10 but is affected by ability modifiers.
	maxHitPoints = 10;
	initAbilityModifiers();
	currentHitPoints = maxHitPoints;
	baseAttackBonus = 1;
	level = 1;
	attacks = 1;
}

Character::Character(int str, int dex, int con, int intel, int wis, int cha, char isP, int lvl)
{
	isPlayer = isP;
	abilityScores[0] = str;
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;
	for (int i = 0; i < 6; i++)
	{
		abilityBonuses[i] = 0;
	}
	maxHitPoints = 10;
	initAbilityModifiers();
	currentHitPoints = maxHitPoints;
	baseAttackBonus = 1;
	level = 1;
	int levelsToGo = lvl - level;
	attacks = 1;
	while (levelsToGo > 0)
	{
		Dice hitDice = Dice();
		int healthRoll = hitDice.roll("1d10[+0]");
		levelUp(healthRoll);
		levelsToGo--;
	}
}

Character::Character(int str, int dex, int con, int intel, int wis, int cha, int lvl)
{
	isPlayer = 'P';
	abilityScores[0] = str;
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;
	for (int i = 0; i < 6; i++)
	{
		abilityBonuses[i] = 0;
	}
	maxHitPoints = 10;
	initAbilityModifiers();
	currentHitPoints = maxHitPoints;
	baseAttackBonus = 1;
	level = 1;
	int levelsToGo = lvl - level;
	attacks = 1;
	while (levelsToGo > 0)
	{
		Dice hitDice = Dice();
		int healthRoll = hitDice.roll("1d10[+0]");
		levelUp(healthRoll);
		levelsToGo--;
	}
}

Character::Character(int lvl) {
	//for creating monsters
	Character();
	isPlayer = 'M';
	Dice lvlDice = Dice();
	for (int l = 0; l < lvl; l++) {
		levelUp(lvlDice.roll("1d6[+0]"));
	}
}


//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
		if (abilityScores[i]<3 || abilityScores[i]>18)
			return false;
	return true;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param damage: damage sustained by the character
void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;
	Report("Player takes " + to_string(damage) + " damage!");
	Notify();
}

void Character::updateFromInventory()
{
	std::vector<Enhancement> currentBonus = wornItems->getBonuses();
	updateBonuses(currentBonus);
	initAbilityModifiers();
}

void Character::updateBonuses(vector<Enhancement> bonuses)
{
	int numberOfBonuses = bonuses.size();
	for (int i = 0; i < 6; i++)
	{
		abilityBonuses[i] = 0;
	}
	armorClassBonus = 0;
	attackBonus = 0;
	damageBonus = 0;
	for (int i = 0; i < numberOfBonuses; i++)
	{
		string bonusType = bonuses.at(i).getType();
		if (bonusType == "Strength")
		{
			abilityBonuses[0] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Dexterity")
		{
			abilityBonuses[1] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Constitution")
		{
			abilityBonuses[2] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Intelligence")
		{
			abilityBonuses[3] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Wisdom")
		{
			abilityBonuses[4] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Charisma")
		{
			abilityBonuses[5] = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Armor Class")
		{
			armorClassBonus = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Attack")
		{
			attackBonus = bonuses.at(i).getBonus();
		}
		else if (bonusType == "Damage")
		{
			damageBonus = bonuses.at(i).getBonus();
		}
	}
}

int* Character::getAbilityScores() {
	return abilityScores;
}

int * Character::getAdjustedAbilityScores()
{
	int tempScores[6];
	for (int i = 0; i < 6; i++)
	{
		tempScores[i] = abilityScores[i] + abilityBonuses[i];
	}
	int* adjustedScores = tempScores;
	return adjustedScores;
}

//! Implementation of a getter method for currentHitPoints
//! @return int: value of currentHitPoints
int Character::getHitPoints()
{
	return currentHitPoints;
}

void Character::setHitPoints(int newHitPoints)
{
	currentHitPoints = newHitPoints;
}

int Character::getMaxHitPoints()
{
	return maxHitPoints;
}

//! Implementation of initializing ability modifiers and their effects: https://www.dandwiki.com/wiki/MSRD:Ability_Scores
void Character::initAbilityModifiers()
{
	maxHitPoints = maxHitPoints - (abilityModifiers[2] * level);
	for (int i = 0; i < 6; i++)
	{
		abilityModifiers[i] = floor((abilityScores[i] + abilityBonuses[i]) / 2) - 5;
	}
	maxHitPoints = maxHitPoints + (abilityModifiers[2] * level);
	if (currentHitPoints > maxHitPoints)
		currentHitPoints = maxHitPoints;
	armorClass = 10 + abilityModifiers[1];
}

int Character::getLevel()
{
	return level;
}

string Character::getClassName()
{
	return className;
}

void Character::levelUp(int diceRoll)
{
	Report("Player levels up!");
	level++;
	baseAttackBonus++;
	attacks = 1 + ((baseAttackBonus - 5) / 5);
	maxHitPoints = maxHitPoints + diceRoll + abilityModifiers[2];
	Notify();
}

int Character::attack(int diceRoll)
{
	//damage is equal to dice roll + strength modifier
	int attack = diceRoll + abilityModifiers[0] + damageBonus;
	Report("Player attacks and deals " + to_string(attack) + " damage!");
	return attack;
}

//! method to return the sum armor class of the character
int Character::getArmorClass()
{
	return armorClass + armorClassBonus;
}

//! method to randomly distribute points on level up
void Character::distributePoints(int points)
{
	while (points != 0)
	{
		int i = rand() % 6;
		abilityScores[i]++;
		points--;
	}
}

int Character::toHit(int diceRoll)
{
	return (diceRoll + abilityModifiers[0] + baseAttackBonus + attackBonus);
}

std::vector<int> Character::toHit()
{
	std::vector<int> attackResults;
	Dice attackRoll = Dice();
	for (int i = 0; i < attacks; i++)
	{
		attackResults.push_back(attackRoll.roll("1d20[+0]") + abilityModifiers[0] + baseAttackBonus + attackBonus- (i * 5));
	}
	return attackResults;
}

void Character::displayStats() {
	string abilityNames[] = { "Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma" };

	printf("Level %d Fighter\n", getLevel());// , getClassName());
	printf("HP: %d/%d\n\n", getHitPoints(), getMaxHitPoints());
	
	printf("AC: %d (+%d)\n", getArmorClass(), armorClassBonus);
	printf("Attack Bonus: %d (+%d)\n", toHit(0), attackBonus);
	printf("Damage Bonus: %d (+%d)\n\n", attack(0), damageBonus);

	for (int i = 0; i < 6; i++) {
		printf("%s: %d [+%d] (+%d)\n", abilityNames[i].c_str(), (abilityScores[i] + abilityBonuses[i]), abilityModifiers[i], abilityBonuses[i]);
	}	
}

void Character::fight(Character* opponent)
{
	string opString = "MONSTER";
	if(opponent->isPlayer == 'P')
		opString = "PLAYER";

	//HANDLES ALL FIGHT LOGIC
	int damageOnOpponent = 0;
	//mutliply by number of attacks
	std::vector<int> attackResults = toHit();
	int numAttacks = attackResults.size();
	int enemyAC = opponent->getArmorClass();
	for (int i = 0; i < numAttacks; i++)
	{
		if (attackResults.at(i) < enemyAC)
		{
			attackResults.erase(attackResults.begin() + i);
		}
	}
	numAttacks = attackResults.size();
	if (numAttacks < 1)
	{
		cout << damageOnOpponent << "All attacks missed!" << endl;
	}
	else
	{
		for (int i = 0; i < numAttacks; i++)
		{
			Dice damageDie = Dice();
			int damageRoll = damageDie.roll("1d6[+0]");
			damageOnOpponent += attack(damageRoll);
		}
	}
	opponent->setHitPoints(opponent->getHitPoints() - damageOnOpponent);
	cout << damageOnOpponent << " damage was done to the " + opString + "!" << endl;
	if (opponent->getHitPoints() <= 0) {
		cout << "The " + opString + " has been defeated!" << endl;
		//handle destory monster
		//probably a method of map that will remove it
	}

	cout << "FIGHT OVER!" << endl << "Press any key to continue";
	characterKeyPress();

}
