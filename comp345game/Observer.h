//! @file 
//! @brief Implementation file for the Observer class  
//! based on example provided by professor in course material
//!
#pragma once
#include "Observable.h"

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observable;

class Observer {
public:
	~Observer();
	virtual void Update() = 0;
	virtual void Update(string s) = 0;
protected:
	Observer();
};