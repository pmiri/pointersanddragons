#include "BullyBuilder.h"

void BullyBuilder::sortAttributes(std::vector<int>* stats)
{
	int str, dex, con, intel, wis, cha;
	str = popHighest(stats);
	con = popHighest(stats);
	dex = popHighest(stats);	
	intel = popHighest(stats);
	cha = popHighest(stats);
	wis = popHighest(stats);	
	pushStats(str, dex, con, intel, wis, cha, stats);
}
