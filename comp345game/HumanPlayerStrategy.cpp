
#include "HumanPlayerStrategy.h"
//#include <iostream>
#include <conio.h>

HumanPlayerStrategy::HumanPlayerStrategy() {
}

inline char playerStrategyKeyPress() {
	int psi = _getche();
	char psinput = static_cast<char>(psi);
	cout << endl;
	return psinput;
}

void HumanPlayerStrategy::doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP) {
	//set up
	bool sinventoryMode = false;
	bool splayerMode = false;

	//check inventory
	string smapString = mapViewP->getMapString();
	char in = playerStrategyKeyPress();
	if (in == 'i' | in == 'I')
	{
		sinventoryMode = !sinventoryMode;
	}
	else if (in == 'p' || in == 'P') {
		splayerMode = !splayerMode;
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
		mapP->moveCharacter(in);
		cout << "use WASD to move the Player" << endl;
	}
	//ask do action (ends turn)
};