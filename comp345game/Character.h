#pragma once
//! @file 
//! @brief Header file for the Character class  
//!

#include <iostream>
#include "Subject.h"
#include "ItemUI.h"
#include <vector>
using namespace std;

#pragma once

//! Class that implements a character 
class Character : public Subject
{
public:
	char isPlayer;
	Inventory* wornItems;
	Backpack* carriedItems;
	ItemUI* itemManager;
	Character();
	Character(int, int, int, int, int, int, char);
	bool validateNewCharacter();
	void hit(int);
	void updateFromInventory();
	void updateBonuses(vector<Enhancement> bonuses);
	int getHitPoints();
	int getMaxHitPoints();
	void initAbilityModifiers();
	int getLevel();
	string getClassName();
	void levelUp(int);
	void distributePoints(int);
	int toHit(int);
	int attack(int);
	int getArmorClass();
	int* getAbilityScores();
	int* getAdjustedAbilityScores();
protected:
	int abilityScores[6];
	int abilityBonuses[6];
	int baseAttackBonus;
	int attackBonus;
	int damageBonus;
	int armorClassBonus;
	int abilityModifiers[6];
	int currentHitPoints;
	int maxHitPoints;
	int armorClass;
	int level;

	string className;
};