
#include "AggressorStrategy.h"
//#include <iostream>
#include <conio.h>

AggressorStrategy::AggressorStrategy() {
}

void AggressorStrategy::doStrategy(char in, Map* mapP, int* turns, MapObject* monsterMapObj) {
	if (monsterMapObj != NULL)
		mapP->moveMonster(*monsterMapObj);
};