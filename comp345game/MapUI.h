#pragma once
#include "Map.h"
#include "Observer.h"

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