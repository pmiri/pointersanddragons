#include "NimbleBuilder.h"

void NimbleBuilder::sortAttributes(std::vector<int>* stats)
{
	int str, dex, con, intel, wis, cha;
	dex = popHighest(stats);
	con = popHighest(stats);
	str = popHighest(stats);
	intel = popHighest(stats);
	cha = popHighest(stats);
	wis = popHighest(stats);
	pushStats(str, dex, con, intel, wis, cha, stats);
}
