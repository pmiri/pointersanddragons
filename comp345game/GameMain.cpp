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
#include "GameLogger.h"

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
	return tolower(input);
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

void ItemMenu() {
	cout << "Welcome to the Item Editor Program! Would you like to create an item, or load an item?" << endl;
	cout << "Press c to create, l to load." << endl;

	Item item;
	string filePath;
	switch (keyPress()) {
	case 'c':
		item = ItemBuilder::buildItem();
		cout << "Would you like to save? (y)" << endl;
		if (keyPress() == 'y')
		{
			cout << "What is the filename you would like to save to?" << endl;
			cin >> filePath;
			ItemBuilder::saveItem(filePath, item);
		}
		break;
	case 'l':
		cout << "What is the filename of the item you want to load?" << endl;
		cin >> filePath;
		item = ItemBuilder::loadItem(filePath);
		item = ItemBuilder::editItem(item);
		cout << "Would you like to save?" << endl;
		if (keyPress() == 'y')
		{
			cout << "What is the filename you would like to save to?" << endl;
			cin >> filePath;
			ItemBuilder::saveItem(filePath, item);
		}
		break;
	default:
		break;
	}
}

Character* CharacterSelect() {
	do {
		cout << "Character - Load(1) or Create(2):" << endl;
		switch (keyPress()) {
		case '1':
			cout << "Please pick a file:" << endl;
			return CharacterEditor::loadCharacter(CHARACTERS_PATH + characterSelection());
			break;
		case '2':
			return CharacterEditor::createCharacter();
			break;
		default:
			cout << "Please select the right value";
			break;
		}
	} while (true);
}

int main() {
	Character* playerCharacter;
	Inventory* playerInventory;
	vector<Enhancement> testEnhancement;
	Enhancement testArmorClassEnhancement;
	Item testHelm;
	Enhancement testStrengthEnhancement;
	Item testBelt;
	Backpack* playerPack;
	ItemUI* itemView;

	GameLogger* logger = new GameLogger();
	logger->Log("Log created");

	cout << "COMP C++ TEAM PROJECT: ONSLAUGHT" << endl;
	cout << endl;
	cout << "Press I to enter the Item editor, M to open the Map/Campaign editor, and anything else to play.\n";
	char in;
	switch (keyPress()) {
	case 'i':
		logger->Log("Item Menu opened.");
		ItemMenu();
		break;
	case 'm':
		logger->Log("Map Creator opened.");
		MapCreator::runMenu();
		break;
	default:
		system("CLS");
		cout << "Welcome to our game!" << endl;
		system("pause");

		//Selecting a map and a character from a list of saved ones
		cout << "Load a Map:" << endl;
		map = MapBuilder::buildFromFile(MAPS_PATH + mapSelection());
		MapUI mapView = MapUI::MapUI(map);
		system("CLS");

		Character *character = new Character;

		bool selected = false;
		character = CharacterSelect();

		//adds the built player to the map
		playerCharacter = character;
		playerCharacter->Connect(logger);
		map->PlacePlayer(playerCharacter);
		map->setAllMonsters();

		playerInventory = new Inventory();

		playerPack = new Backpack();
		itemView = new ItemUI(playerInventory, playerPack);

		playerCharacter->wornItems = playerInventory;
		playerCharacter->carriedItems = playerPack;
		playerCharacter->itemManager = itemView;
		playerCharacter->strategy = new HumanPlayerStrategy();
		playerCharacter->updateFromInventory();

		playerInventory = new Inventory();

		bool inventoryMode = false;
		bool playerMode = false;

		system("CLS");
		map->Notify();
		cout << "use WASD to move the Player" << endl;

		int* turnCount = new int;
		list<MapObject> gameMonsterList;
		bool newMap = false;

		//GAME MAIN
		while (!gameFinished) {
			newMap = false;
			string nextMapPath = map->path;
			int nextOrPrev = 0;

			*turnCount = 6;
			while (*turnCount > 0) {
				playerCharacter->strategy->doStrategy(map, &mapView, itemView, playerCharacter, turnCount, nullptr);
				cout << *turnCount << " player turns left";
				switch (map->mapSwitch) {
				case 1:
					newMap = true;
					nextMapPath = map->next;
					break;
				case -1:
					newMap = true;
					nextMapPath = map->prev;
					break;
				default:
					break;
				}
			}

			if (newMap) {
				//Moving forward and no maps left
				if (nextMapPath == "" && nextOrPrev == 1) {
					cout << "YOU WIN" << endl;
					gameFinished = true;
					continue;
				}
				else if (nextMapPath == "" && nextOrPrev == -1) {
					cout << "You are at the start" << endl;
					continue;
				}
				map = MapBuilder::buildFromFile(MAPS_PATH + nextMapPath);
				map->Notify();
				continue;
			}

			*turnCount = 6;
			while (*turnCount > 0) {
				gameMonsterList = list<MapObject>();
				gameMonsterList = map->getListOfMonsterObjs();
				for each (MapObject monObj in gameMonsterList)
				{
					monObj.getCharacter()->strategy->doStrategy(map, &mapView, itemView, playerCharacter, turnCount, &monObj);
				}
				*turnCount = *turnCount - 1;
				cout << *turnCount << " monster turns left";
			}

			//TODO NPC turn
		}

		delete playerCharacter;
		delete playerInventory;
		delete playerPack;
		delete itemView;
		delete campaign;

		break;
	}


	//TODO: 	Toggling a view of character information(player or opponents) and chest content during play.

	//TODO: 	Ending the game by having the character stepping on the exit point and going up a level

	logger->Log("Log Over");
	system("pause");

	delete logger;
	return 0;
}

