#pragma once
#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

class MapBuilder 
{
public:
	static Map *buildFromFile(string path);
	static Map *buildFromMap(Map map);

private:


};