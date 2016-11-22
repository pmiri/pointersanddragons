#include "Loggable.h"
#include "Loggable.h"
#include "Logger.h"
#include <iostream>

Loggable::Loggable() {
	_loggers = new list<Logger*>;
}
Loggable::~Loggable() {
	delete _loggers;
}
list<Logger*> Loggable::getLoggers()
{
	return *_loggers;
}
void Loggable::Connect(Logger* o) {
	_loggers->push_back(o);
};
void Loggable::Deconnect(Logger* o) {
	_loggers->remove(o);
};
void Loggable::Report(string message) {
	list<Logger *>::iterator i = _loggers->begin();
	for (; i != _loggers->end(); ++i)
		(*i)->Log(message);
};
