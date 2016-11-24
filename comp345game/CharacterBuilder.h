#pragma once
#include "Character.h"

class CharacterBuilder
{
public:
	Character* getCharacter() { return builtCharacter; };
	void buildCharacter(int level);	
protected:
	Character* builtCharacter;
	int getHighest(std::vector<int> stats);
	virtual void sortAttributes(std::vector<int>* stats) = 0;
	std::vector<int> rollStats();
	int popHighest(std::vector<int>* stats);
	void pushStats(int str, int dex, int con, int intel, int wis, int cha, std::vector<int>* stats);
};