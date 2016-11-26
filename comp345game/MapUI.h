//! @file 
//! @brief Declaration file for the MapUI class  
//!
#pragma once
using namespace std;
#include "Map.h"


class MapUI : public Observer
{
public:
	MapUI();
	MapUI(Map* m);
	void PrintMap();
	void Update();
	string getMapString();
private:
	Map *_subject;
	string mapString;
};

class CharacterStrategy {
public:
	CharacterStrategy::CharacterStrategy();
	virtual void doStrategy(char in, Map* mapP, int* turns, MapObject* monsterMapObj = NULL) = 0;
};

