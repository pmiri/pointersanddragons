
#include "HumanPlayerStrategy.h"
//#include <iostream>
#include <conio.h>

HumanPlayerStrategy::HumanPlayerStrategy() {
	sinventoryMode = false;
	splayerMode = false;
}

void HumanPlayerStrategy::doStrategy(char in, Map* mapP, int* turns, MapObject* monsterMapObj) {
	bool goodMove = mapP->moveCharacter(in);
	cout << "use WASD to move the Player" << endl;
	if (goodMove)
		*turns = *turns - 1;
};