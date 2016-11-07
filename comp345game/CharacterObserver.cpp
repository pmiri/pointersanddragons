#include "CharacterObserver.h"
#include "Character.h"
#include <iostream>
using namespace std;

CharacterObserver::CharacterObserver() {
};
CharacterObserver::CharacterObserver(Character* s) {
	//Upon instantiation, attaches itself to a Character
	_subject = s;
	_subject->Attach(this);
	_subject->Notify();
};
CharacterObserver::~CharacterObserver() {
	//Upon destruction, detaches itself from its Character      
	_subject->Detach(this);
};
void CharacterObserver::Update() {
	display();
};
void CharacterObserver::display() {
	int *abilityScores = _subject->getAbilityScores();
	int level = _subject->getLevel();
	int hp = _subject->getMaxHitPoints();
	cout << "Level: " << level << endl
		<< "HP: " << hp << endl
		<< "Str: " << abilityScores[0] << endl
		<< "Dex: " << abilityScores[1] << endl
		<< "Con: " << abilityScores[2] << endl
		<< "Intel: " << abilityScores[3] << endl
		<< "Wis: " << abilityScores[4] << endl
		<< "Cha: " << abilityScores[5] << endl;
	system("pause");
};