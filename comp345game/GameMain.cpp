#include <iostream>
#include <conio.h>
#include "dirent.h"
#include <list>
#include <string>

#include "MapBuilder.h"
#include "CharacterEditor.h"

using namespace std;

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

int main() {
	Character *ch = CharacterEditor::createCharacter();
	ch = CharacterEditor::editCharacter(ch);
	cout << "COMP C++ TEAM PROJECT: ONSLAUGHT" << endl;
	cout << endl;
	cout << "Welcome to our stupid game." << endl;
	system("pause");
	
	system("CLS");
	
	//Selecting a map and a character from a list of saved ones
	cout << "Please Select a Map:" << endl;
	Map *map = MapBuilder::buildFromFile(MAPS_PATH + mapSelection());
	system("CLS");
	
	cout << "Please Select a Character:" << endl;
	Character *character = CharacterEditor::loadCharacter(CHARACTERS_PATH + characterSelection());
	system("CLS");

	//TODO: 	Adapting the map elements(opponents, treasure) to the level of the character upon entry

	//TODO: 	Starting the game by having the player character placed on the starting point
	
	//TODO: 	Moving the character, square by square on the map
	
	//TODO: 	Toggling a view of character information(player or opponents) and chest content during play.
	
	//TODO: 	Ending the game by having the character stepping on the exit point and going up a level
	
	system("pause");
	return 0;
}
