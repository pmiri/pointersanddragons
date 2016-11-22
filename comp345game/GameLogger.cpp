#include "GameLogger.h"
#include <iostream>
#include <sstream>
#include <ctime>

// For main
#include "Character.h"
#include "Dice.h"

using namespace std;

GameLogger::GameLogger(string path)
{
	//If no specified path, create one at time of now
	if (path == "") {
		char buffer[80];
		time_t rawtime;
		struct tm timeinfo;
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		strftime(buffer, 80, "%I-%M-%p", &timeinfo);

		std::stringstream ss;
		ss << "log-" << buffer << ".txt";
		file_path = ss.str();
	}
}

GameLogger::GameLogger(Loggable* m, string path) {
	_subject = m;
	_subject->Connect(this);

	//If no specified path, create one at time of now
	if (path == "") {
		char buffer[80];
		time_t rawtime;
		struct tm timeinfo;
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);

		strftime(buffer, 80, "%I-%M-%p", &timeinfo);

		std::stringstream ss;
		ss << "log-" << buffer << ".txt";
		file_path = ss.str();
	}
}

void GameLogger::Log(string s) {
	if (!activated)
		return;

	//Either write or append
	file.open(file_path, std::ofstream::out | std::ofstream::app);
	file << s << endl;
	file.close();
}

void GameLogger::activate() {
	activated = true;
}

void GameLogger::deactivate() {
	activated = false;
}

string GameLogger::getPath() {
	return file_path;
}

GameLogger::~GameLogger()
{
}


int main() {
	GameLogger* logger = new GameLogger();
	Character* player = new Character();

	system("pause");
	cout << "GAME LOGGER TEST MAIN" << endl;
	system("pause");

	Dice* d = new Dice();
	d->Connect(logger);
	//xdy[+z]
	d->roll("2d6[+1]");
	player->Connect(logger);

	player->attack(10);
	
	delete d;
	delete player;
	delete logger;


	return 0;
}
