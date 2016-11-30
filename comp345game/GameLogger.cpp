#include "GameLogger.h"
#include <iostream>
#include <sstream>
#include <ctime>

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
	else {
		file_path = path;
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
	else {
		file_path = path;
	}
}

void GameLogger::Log(string s) {
	if (!activated)
		return;

	//Either write or append
	file.open(FOLDER_PATH + file_path, std::ofstream::out | std::ofstream::app);
	file << s << endl;
	file.close();
}

void GameLogger::toggle() {
	activated = !activated;
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

/*
int main() {
	GameLogger* logger = new GameLogger();

	cout << "GAME LOGGER TEST MAIN" << endl;
	system("pause");


	logger->Log("Starting Tests");

	logger->Log("Creating Dice");
	Dice* d = new Dice();
	d->Connect(logger);
	d->roll("2d6[+1]");

	logger->Log("Closing Tests");
	
	delete d;
	delete logger;


	return 0;
}
*/
