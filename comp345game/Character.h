#pragma once
//! @file 
//! @brief Header file for the Character class  
//!
using namespace std;
#include <iostream>
#include "Subject.h"
#include "ItemUI.h"
#include <vector>

class CharacterStrategy;//forward declaration to help compilation

//! Class that implements a character 
class Character : public Subject
{
public:
	char isPlayer;
	Inventory* wornItems;
	Backpack* carriedItems;
	ItemUI* itemManager;
	CharacterStrategy* strategy;//INCLUDED VIA CharacterStrategy.cpp 
	Character();
	Character(int, int, int, int, int, int, char);
	bool validateNewCharacter();
	void hit(int);
	void updateFromInventory();
	void updateBonuses(vector<Enhancement> bonuses);
	
	void initAbilityModifiers();
	
	
	void levelUp(int);
	void distributePoints(int);
	int toHit(int);

	void displayStats();
	//Player stats
	string getClassName();
	int getHitPoints();
	int getMaxHitPoints();
	int getLevel();
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

////#include "MapUI.h";
//class CharacterStrategy {
//public:
//	CharacterStrategy::CharacterStrategy();
//	virtual void doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP);
//};