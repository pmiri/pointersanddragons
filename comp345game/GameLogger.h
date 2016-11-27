#pragma once
#include "Logger.h"
#include "Loggable.h"
#include <string>
#include <fstream>

class GameLogger: public Logger
{
public:
	GameLogger(string path = "");
	GameLogger(Loggable* loggable, string path = "");
	void Log(string s);
	
	void toggle();
	void activate();
	void deactivate();

	string getPath();

	~GameLogger();

private:
	bool activated = true;
	Loggable *_subject;
	ofstream file;
	string file_path;
};

