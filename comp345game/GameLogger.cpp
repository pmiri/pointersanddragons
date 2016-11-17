#include "GameLogger.h"
#include <iostream>

using namespace std;

GameLogger::GameLogger()
{
}

GameLogger::GameLogger(Map* m) {
	_subject = m;
	_subject->Attach(this);

	cout << typeid(_subject).name() << endl;
}

GameLogger::GameLogger(Character* c) {
	_subject = c;
	_subject->Attach(this);
}

GameLogger::GameLogger(Dice* d) {
	_subject = d;
	_subject->Attach(this);
}

void GameLogger::Update(string s) {
	if (!activated)
		return;
	if (typeid(_subject) == typeid(Map)) {

	}else if(true) {

	}
}

void GameLogger::activate() {
	activated = true;
}

void GameLogger::deactivate() {
	activated = false;
}

GameLogger::~GameLogger()
{
}

int main() {

	system("pause");


	return 0;
}