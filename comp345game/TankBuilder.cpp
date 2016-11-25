#include "TankBuilder.h"

void TankBuilder::sortAttributes(std::vector<int>* stats)
{
	int str, dex, con, intel, wis, cha;
	con = popHighest(stats);
	dex = popHighest(stats);	
	str = popHighest(stats);
	intel = popHighest(stats);
	cha = popHighest(stats);
	wis = popHighest(stats);
	pushStats(str, dex, con, intel, wis, cha, stats);
}
