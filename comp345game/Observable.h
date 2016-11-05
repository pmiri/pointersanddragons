//! @file 
//! @brief Declaration file for the Observable class  
//! based on example provided by professor in course material
//!
#pragma once
#include "Observer.h"
#include <list>
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observer;

class Observable {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Observable();
	~Observable();
	list<Observer*> getObservers();
private:
	list<Observer*> *_observers;
};
