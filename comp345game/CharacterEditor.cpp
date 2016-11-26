#include "CharacterEditor.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>

Character *CharacterEditor::createCharacter() {//(int str, int dex, int con, int intel, int wis, int cha, char isP)
	bool valid = false;
	int str, dex, con, intel, wis, cha;
	while (!valid) {
		cout << "Enter character strength:" << endl;
		cin >> str;
		cout << "Enter character dexterity:" << endl;
		cin >> dex;
		cout << "Enter character constitution:" << endl;
		cin >> con;
		cout << "Enter character intelligence:" << endl;
		cin >> intel;
		cout << "Enter character wisdom:" << endl;
		cin >> wis;
		cout << "Enter character charisma:" << endl;
		cin >> cha;

		//only possible character type is fighter
		char isP = 'P';//changed from F
		Character *ch = new Fighter(str, dex, con, intel, wis, cha, isP);
		valid = ch->validateNewCharacter();

		if (!valid) {
			cout << "Please enter valid modifiers (2 < x < 19)." << endl;
		}
		else {
			cout << "Valid character entered." << endl;
			return ch;
		}
	}
}

Character *CharacterEditor::editCharacter(Character *ch) {
	int *abilityScores = ch->getAbilityScores();
	bool valid = false;
	int str, dex, con, intel, wis, cha;
	while (!valid) {
		cout << "Enter character strength (currently " <<  abilityScores[0] <<"):" << endl;
		cin >> str;
		str = str == NULL ? abilityScores[0] : str;
		cout << "Enter character dexterity (currently " << abilityScores[1] << "):" << endl;
		cin >> dex;
		dex = dex == NULL ? abilityScores[1] : dex;
		cout << "Enter character constitution (currently " << abilityScores[2] << "):" << endl;
		cin >> con;
		con = con == NULL ? abilityScores[2] : con;
		cout << "Enter character intelligence (currently " << abilityScores[3] << "):" << endl;
		cin >> intel;
		intel = intel == NULL ? abilityScores[3] : intel;
		cout << "Enter character wisdom (currently " << abilityScores[4] << "):" << endl;
		cin >> wis;
		wis = wis == NULL ? abilityScores[4] : wis;
		cout << "Enter character charisma (currently " << abilityScores[5] << "):" << endl;
		cin >> cha;
		cha = cha == NULL ? abilityScores[5] : cha;

		//only possible character type is fighter
		char isP = 'F';
		Character *ch = new Fighter(str, dex, con, intel, wis, cha, isP);
		valid = ch->validateNewCharacter();

		if (!valid) {
			cout << "Please enter valid modifiers (2 < x < 19)." << endl;
			return ch;
		}
		else {
			cout << "Valid character entered." << endl;
		}
	}
}

Character *CharacterEditor::loadCharacter(string path) {
	string line = "";
	ifstream myfile;
	int str, dex, con, intel, wis, cha, level;
	char isP;
	myfile.open(path);
	if (myfile.is_open())
	{
		if (getline(myfile, line))
			isP = *(line.c_str());
		else return nullptr;
		if (getline(myfile, line))
			level = atoi(line.c_str());
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

		if (isP == 'P') {
			Character *character = new Fighter(str, dex, con, intel, wis, cha, isP, level);
			return character;
		}
		else {
			Character *character = new Character(str, dex, con, intel, wis, cha, isP, level);
			return character;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		return nullptr;
	}

}

void CharacterEditor::saveCharacterToFile(string path, Character ch) {
	ofstream myfile;
	int *abilityScores = ch.getAbilityScores();
	myfile.open(path);
	myfile << ch.isPlayer << endl;
	myfile << ch.getLevel() << endl;
	myfile << abilityScores[0] << endl;
	myfile << abilityScores[1] << endl;
	myfile << abilityScores[2] << endl;
	myfile << abilityScores[3] << endl;
	myfile << abilityScores[4] << endl;
	myfile << abilityScores[5] << endl;
	myfile.close();
}