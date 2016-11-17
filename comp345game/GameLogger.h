#pragma once
#include "Map.h"
#include "Observer.h"
#include "Dice.h"

class GameLogger: public Observer
{
public:
	GameLogger();
	GameLogger(Map* m);
	GameLogger(Dice* d);
	// GameLogger(GAME MAIN?);
	GameLogger(Character* c);
	void Update(string s);
	void activate();
	void deactivate();

	~GameLogger();

private:
	bool activated = true;
	Observable *_subject;
};

