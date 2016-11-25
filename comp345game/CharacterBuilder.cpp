#include "CharacterBuilder.h"

void CharacterBuilder::buildCharacter(int level)
{
	std::vector<int> *stats = new std::vector<int>();
	*stats = rollStats();
	sortAttributes(stats);
	builtCharacter = new Character(stats->at(0), stats->at(1), stats->at(2), stats->at(3), stats->at(4), stats->at(5), level);
}

int CharacterBuilder::getHighest(std::vector<int> stats)
{
	int length = stats.size();
	int max = 0;
	int maxIndex = -1;
	for (int i = 0; i < length; i++)
	{
		if (stats.at(i) > max)
		{
			max = stats.at(i);
			maxIndex = i;
		}
	}
	return maxIndex;
}

std::vector<int> CharacterBuilder::rollStats()
{
	std::vector<int> stats;
	Dice abilityDice = Dice();
	for (int i = 0; i < 6; i++)
	{
		std::vector<int> rolls;
		for (int j = 0; j < 4; j++)
		{
			rolls.push_back(abilityDice.roll("1d6"));
		}
		stats.push_back(0);
		for (int k = 0; k < 3; k++)
		{
			int highestIndex = getHighest(rolls);
			stats.at(i) += rolls.at(highestIndex);
			rolls.erase(rolls.begin() + highestIndex);
		}
	}
	return stats;
}

int CharacterBuilder::popHighest(std::vector<int>* stats)
{
	int index = getHighest(*stats);
	int temp = stats->at(index);
	stats->erase(stats->begin() + index);
	return temp;
}

void CharacterBuilder::pushStats(int str, int dex, int con, int intel, int wis, int cha, std::vector<int>* stats)
{
	stats->push_back(str);
	stats->push_back(dex);
	stats->push_back(con);
	stats->push_back(intel);
	stats->push_back(wis);
	stats->push_back(cha);
}
