#pragma once
#include <string>

using namespace std;

class Logger
{
public:
	Logger();
	virtual void Log(string message) = 0;
	
protected:
	~Logger();
};

