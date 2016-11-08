#include "CharacterEditor.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

void CharacterEditor::createCharacter() {//(int str, int dex, int con, int intel, int wis, int cha, char isP)
	cout << "" << endl;
}

void CharacterEditor::editCharacter() {

}

Character *CharacterEditor::loadCharacter(string path) {
	string line = "";
	ifstream myfile;
	int str, dex, con, intel, wis, cha;
	char isP;
	myfile.open(path);
	if (myfile.is_open())
	{
		if (getline(myfile, line))
			isP = *(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			str = atoi(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			dex = atoi(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			con = atoi(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			intel = atoi(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			wis = atoi(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			cha = atoi(line.c_str());
		else return nullptr;
		myfile.close();

		if (isP == 'F') {
			Character *character = new Fighter(str, dex, con, intel, wis, cha, isP);
			return character;
		}
		else {
			Character *character = new Character(str, dex, con, intel, wis, cha, isP);
			return character;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		return nullptr;
	}

}

int main() {
	//Character *ch = CharacterEditor::loadCharacter("C:\\Users\\jacob\\Documents\\dumps\\player.txt");

	return 0;
};