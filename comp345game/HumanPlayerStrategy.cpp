
#include "HumanPlayerStrategy.h"
//#include <iostream>
#include <conio.h>

HumanPlayerStrategy::HumanPlayerStrategy() {
	sinventoryMode = false;
	splayerMode = false;
}

inline char playerStrategyKeyPress() {
	int psi = _getche();
	char psinput = static_cast<char>(psi);
	cout << endl;
	return psinput;
}

void HumanPlayerStrategy::doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP, int* turns, MapObject* monsterMapObj) {
	//set up
	bool validMove = true;

	//check inventory
	string smapString = mapViewP->getMapString();
	char in = playerStrategyKeyPress();
	if (in == 'i' | in == 'I')
	{
		sinventoryMode = !sinventoryMode;
		validMove = false;
	}
	else if (in == 'p' || in == 'P') {
		splayerMode = !splayerMode;
		validMove = false;
	}
	if (sinventoryMode)
	{
		system("cls");
		bool svalidEquip = itemViewP->organizeItems(in);
		itemViewP->PrintInventory();
		cout << "Press i to exit inventory, or press 0-9 to equip items from backpack." << endl;
		if (svalidEquip)
			thisCharacterP->updateFromInventory();
	}
	else if (splayerMode) {
		system("cls");
		thisCharacterP->displayStats();
	}
	else
	{
		bool goodMove = mapP->moveCharacter(in);
		cout << "use WASD to move the Player" << endl;
		if(validMove && goodMove)
			*turns = *turns -1;
	}
	//ask do action (ends turn)
};