#include "Observable.h"
#include "Observer.h"
#include <iostream>

Observable::Observable() {
	_observers = new list<Observer*>;
}
Observable::~Observable() {
	delete _observers;
}
void Observable::Attach(Observer* o) {
	_observers->push_back(o);
};
void Observable::Detach(Observer* o) {
	_observers->remove(o);
};
void Observable::Notify() {
	cout << "Notified!" << endl;
	list<Observer *>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->Update();
};