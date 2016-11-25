#include "MonsterBuilder.h"

void MonsterBuilder::sortAttributes(std::vector<int>* stats)
{
	int str, dex, con, intel, wis, cha;
	str = popHighest(stats); //More damage and chance to hit
	con = popHighest(stats); //More health and fort save
	dex = popHighest(stats); //More AC and reflex save
	wis = popHighest(stats); //More Will save	
	cha = popHighest(stats); //More resistance to intimidation
	intel = popHighest(stats); //More skill points, so, worthless
	pushStats(str, dex, con, intel, wis, cha, stats);
}
