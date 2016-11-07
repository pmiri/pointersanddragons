//! @file 
//! @brief Implementation file for the Character class  
//!

#include "Character.h"
#include <stdlib.h>
#include <time.h>
#include<iostream>

//! Constructor: creates character with random ability scores 
Character::Character()
{
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

	level = 1;
}

//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{
	abilityScores[0] = str;
	abilityScores[1] = dex;
	abilityScores[2] = con;
	abilityScores[3] = intel;
	abilityScores[4] = wis;
	abilityScores[5] = cha;

	//default hit points is 10 but is affected by ability modifiers.
	maxHitPoints = 10;
	initAbilityModifiers();
	currentHitPoints = maxHitPoints;

	level = 1;
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
	Notify();
}

int* Character::getAbilityScores() {
	return abilityScores;
}

//! Implementation of a getter method for currentHitPoints
//! @return int: value of currentHitPoints
int Character::getHitPoints()
{
	return currentHitPoints;
}

int Character::getMaxHitPoints()
{
	return maxHitPoints;
}

//! Implementation of initializing ability modifiers and their effects: https://www.dandwiki.com/wiki/MSRD:Ability_Scores
void Character::initAbilityModifiers()
{
	for (int i = 0; i < 6; i++)
	{
		abilityModifiers[i] = floor(abilityScores[i] / 2) - 5;
	}

	maxHitPoints = maxHitPoints + abilityModifiers[2];
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
	level++;
	maxHitPoints = maxHitPoints + diceRoll;
	Notify();
}

int Character::attack(int diceRoll)
{
	//damage is equal to dice roll + strength modifier
	return diceRoll + abilityModifiers[0];
}

//! method to return the sum armor class of the character
int Character::getArmorClass()
{
	return armorClass;
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