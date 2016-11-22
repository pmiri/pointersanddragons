#pragma once
#include "Logger.h"
#include <list>
using namespace std;

class Loggable
{
public:
	virtual void Connect(Logger* l);
	virtual void Deconnect(Logger* l);
	virtual void Report(string message);
	Loggable();
	~Loggable();
	list<Logger*> getLoggers();
private:
	list<Logger*> *_loggers;

};

