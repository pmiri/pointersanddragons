//
//#include "HumanPlayerStrategy.h"
//#include <iostream>
//#include <conio.h>
//
//HumanPlayerStrategy::HumanPlayerStrategy() {
//}
//
//inline char playerStrategyKeyPress() {
//	int i = _getche();
//	char input = static_cast<char>(i);
//	cout << endl;
//	return input;
//}
//
//void HumanPlayerStrategy::doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP) {
//	//set up
//	bool inventoryMode = false;
//	bool playerMode = false;
//
//	//check inventory
//	string mapString = mapViewP->getMapString();
//	char in = playerStrategyKeyPress();
//	if (in == 'i' | in == 'I')
//	{
//		inventoryMode = !inventoryMode;
//	}
//	else if (in == 'p' || in == 'P') {
//		playerMode = !playerMode;
//	}
//	if (inventoryMode)
//	{
//		system("cls");
//		bool validEquip = itemViewP->organizeItems(in);
//		itemViewP->PrintInventory();
//		cout << "Press i to exit inventory, or press 0-9 to equip items from backpack." << endl;
//		if (validEquip)
//			thisCharacterP->updateFromInventory();
//	}
//	else if (playerMode) {
//		system("cls");
//		thisCharacterP->displayStats();
//	}
//	else
//	{
//		mapP->moveCharacter(in);
//		cout << "use WASD to move the Player" << endl;
//	}
//	//ask do action (ends turn)
//};