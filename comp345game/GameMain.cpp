#include <iostream>
#include <conio.h>
#include "dirent.h"
#include <list>
#include <string>
#include <iostream>
#include <stdlib.h>//for clearning console on windows
#include "ItemUI.h"
#include "MapBuilder.h"
#include "CharacterEditor.h"
#include "MapUI.h"
#include "Campaign.h"
#include "MapCreator.h"
#include "ItemBuilder.h"
#include "HumanPlayerStrategy.h"

using namespace std;

static bool gameFinished = false;
Map *map;
Campaign *campaign;

const string MAPS_PATH = "../maps/";
const string CHARACTERS_PATH = "../characters/";

inline char keyPress() {
	int i = _getche();
	char input = static_cast<char>(i);
	cout << endl;
	return input;
}

//Reads all possible files available
string mapSelection() {
	list<string> maps;
	DIR *dir;
	struct dirent *ent;
	campaign = new Campaign(3);
	if ((dir = opendir(MAPS_PATH.c_str())) != NULL) {
		/* print all the files and directories within directory */
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i < 0) {
				i++;
				continue;
			}
			printf("[%d] %s\n", i, ent->d_name);
			maps.push_back(ent->d_name);
			string name = ent->d_name;
			if (name.find("campaign") != std::string::npos) {
				campaign->addMap(*MapBuilder::buildFromFile(MAPS_PATH + ent->d_name));
			}
			i++;
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("Could not find map directory.");
		return "" + EXIT_FAILURE;
	}

	char c = keyPress();
	int index = c - 48;

	for (int i = 0; i < index; i++) {
		maps.pop_front();
	}
	return maps.front();
}

//Reads all possible files available
string characterSelection() {
	list<string> characters;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(CHARACTERS_PATH.c_str())) != NULL) {
		/* print all the files and directories within directory */
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i < 0) {
				i++;
				continue;
			}
			printf("[%d] %s\n", i, ent->d_name);
			characters.push_back(ent->d_name);
			i++;
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("Could not find characters directory.");
		return "" + EXIT_FAILURE;
	}

	char c = keyPress();
	int index = c - 48;

	for (int i = 0; i < index; i++) {
		characters.pop_front();
	}
	return characters.front();
}

void changeMap(bool next) {
	*map = next ? campaign->nextMap() : campaign->previousMap();
}

int main() {
	cout << "COMP C++ TEAM PROJECT: ONSLAUGHT" << endl;
	cout << endl;
	cout << "Press I to enter the item editor, M to open the Map/Campaign eidtor, and anything else to play.\n";
	char in;
	in = keyPress();
	if (in == 'i')
	{
		cout << "Welcome to the Item Editor Program! Would you like to create an item, or load an item?" << endl;
		cout << "Press c to create, l to load." << endl;
		in = keyPress();
		if (in == 'c')
		{
			Item builtItem = ItemBuilder::buildItem();
			cout << "Would you like to save?" << endl;
			string input;
			cin >> input;
			if (input == "yes" || input == "y")
			{
				string filePath;
				cout << "What is the filename you would like to save to?" << endl;
				cin >> filePath;
				ItemBuilder::saveItem(filePath, builtItem);
			}
		}
		else if (in == 'l')
		{
			string filePath;
			cout << "What is the filename of the item you want to load?" << endl;
			cin >> filePath;
			Item loadedItem = ItemBuilder::loadItem(filePath);
			loadedItem = ItemBuilder::editItem(loadedItem);
			cout << "Would you like to save?" << endl;
			string input;
			cin >> input;
			if (input == "yes" || input == "y")
			{
				cout << "What is the filename you would like to save to?" << endl;
				cin >> filePath;
				ItemBuilder::saveItem(filePath, loadedItem);
			}
		}
		else
		{
			cout << "I didn't understand that! Would you like to try again?" << endl;
			cout << "Press q to quit" << endl;
			in = keyPress();
			if (in == 'q')
				return 0;
		}		
	}
	else if (in == 'm')
	{
		MapCreator::runMenu();
	}
	else
	{
		cout << endl;
		cout << "Welcome to our game!" << endl;
		system("pause");

		system("CLS");

		//Selecting a map and a character from a list of saved ones
		cout << "Load a Map:" << endl;
		map = MapBuilder::buildFromFile(MAPS_PATH + mapSelection());
		MapUI mapView = MapUI::MapUI(map);
		system("CLS");

		Character *character;


		do {
			cout << "Character - Load(1) or Create(2):" << endl;
			in = keyPress();
			if (in == '1') {
				cout << "Please pick a file:" << endl;
				character = CharacterEditor::loadCharacter(CHARACTERS_PATH + characterSelection());
			}
			else if (in == '2')
				character = CharacterEditor::createCharacter();
			else
				cout << "Please select the right value";
		} while (in != '1' && in != '2');
		//adds the built player to the map
		Character* playerCharacter = new Character;
		//(map->getMapObjectAt(map->BeginPositionX, map->BeginPositionY)).setCharacter(playerCharacter);
		map->PlacePlayer(playerCharacter);
		Inventory* playerInventory = new Inventory();
		vector<Enhancement> testEnhancement;
		Enhancement testArmorClassEnhancement = Enhancement("Armor Class", 4);
		testEnhancement.push_back(testArmorClassEnhancement);
		Item testHelm = Item("Helmet", testEnhancement, "Helmet of Testing");
		playerInventory->replaceItem(testHelm);
		testEnhancement.pop_back();
		Enhancement testStrengthEnhancement = Enhancement("Strength", 3);
		testEnhancement.push_back(testStrengthEnhancement);
		Item testBelt = Item("Belt", testEnhancement, "Belt of Testing");
		Backpack* playerPack = new Backpack();
		playerPack->replaceItem(testBelt);
		ItemUI* itemView = new ItemUI(playerInventory, playerPack);
		playerCharacter->wornItems = playerInventory;
		playerCharacter->carriedItems = playerPack;
		playerCharacter->itemManager = itemView;
		playerCharacter->strategy = new HumanPlayerStrategy();
		bool inventoryMode = false;
		bool playerMode = false;
		system("CLS");
		map->Notify();
		cout << "use WASD to move the Player" << endl;

		//TODO: 	Adapting the map elements(opponents, treasure) to the level of the character upon entry

		//TODO: 	Starting the game by having the player character placed on the starting point

		//TODO: 	Moving the character, square by square on the map

		while (!gameFinished) {
			playerCharacter->strategy->doStrategy(map, &mapView, itemView, playerCharacter);
		}
		//while (!gameFinished) {
		//	//check inventory
		//	string mapString = mapView.getMapString();
		//	in = keyPress();
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
		//		bool validEquip = itemView->organizeItems(in);
		//		itemView->PrintInventory();
		//		cout << "Press i to exit inventory, or press 0-9 to equip items from backpack." << endl;
		//		if (validEquip)
		//			playerCharacter->updateFromInventory();
		//	}
		//	else if (playerMode) {
		//		system("cls");
		//		playerCharacter->displayStats();
		//	}
		//	else
		//	{
		//		map->moveCharacter(in);
		//		cout << "use WASD to move the Player" << endl;
		//	}
		//	//ask do action (ends turn)

		//	//head to next map if prompted
		//	if (map->getNextMap() == -1)
		//	{
		//		changeMap(false);
		//		map->PlacePlayer(playerCharacter);
		//	}
		//	else if (map->getNextMap() == 1)
		//	{
		//		changeMap(true);
		//		map->PlacePlayer(playerCharacter);
		//	}
		//}
		delete playerCharacter;
		delete playerInventory;
		delete playerPack;
		delete itemView;
		delete campaign;
	}	
	//TODO: 	Toggling a view of character information(player or opponents) and chest content during play.
	
	//TODO: 	Ending the game by having the character stepping on the exit point and going up a level
	
	system("pause");
	return 0;
}


