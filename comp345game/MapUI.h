//! @file 
//! @brief Declaration file for the MapUI class  
//!
#pragma once
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
	virtual void doStrategy(Map* mapP, MapUI* mapViewP, ItemUI* itemViewP, Character* thisCharacterP);
};

