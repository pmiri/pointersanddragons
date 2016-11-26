#pragma once
#include "Character.h"

class CharacterBuilder
{
public:
	Character* getCharacter() { return builtCharacter; };
	void buildCharacter(int level);
	int popHighest(std::vector<int>* stats);
	int getHighest(std::vector<int> stats);
	std::vector<int> rollStats();
protected:
	Character* builtCharacter;	
	virtual void sortAttributes(std::vector<int>* stats) = 0;	
	void pushStats(int str, int dex, int con, int intel, int wis, int cha, std::vector<int>* stats);
};