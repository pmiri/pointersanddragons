#pragma once

#include "Loggable.h"
#include <string>
#include <iostream>
using namespace std;

class Dice : public Loggable
{
	public:
		int roll(string input);
};