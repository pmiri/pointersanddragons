#pragma once
#include <string>
#include <iostream>
using namespace std;

class Dice : public Observable
{
	public:
		static int roll(string input);
};