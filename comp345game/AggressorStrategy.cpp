
#include "AggressorStrategy.h"
//#include <iostream>
#include <conio.h>

AggressorStrategy::AggressorStrategy() {
}

void AggressorStrategy::doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP, int* turns, MapObject* monsterMapObj) {
	mapP->moveMonster(*monsterMapObj);
};