#pragma once
//! @file 
//! @brief Header file for the Character class  
//!

#include <iostream>
using namespace std;

#pragma once

//! Class that implements a character 
class Character
{
public:
	Character();
	Character(int, int, int, int, int, int);
	bool validateNewCharacter();
	void hit(int);

	int getHitPoints();
	int getMaxHitPoints();
	void initAbilityModifiers();
	int getLevel();
	string getClassName();
	void levelUp(int);
	void distributePoints(int);
	int attack(int);
	int getArmorClass();
protected:
	int abilityScores[6];
	int abilityModifiers[6];
	int currentHitPoints;
	int maxHitPoints;
	int armorClass;
	int level;

	string className;
};

