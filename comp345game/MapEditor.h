//! @file 
//! @brief Implementation file for the MapEditor class  
//! The MapEditor class generates a Map class from .txt file
//!
#pragma once

using namespace std;
#include "Map.h"

class MapEditor
{
public:
	MapEditor();
	MapEditor(string);
	void loadMapFromFile(string);
	bool validMapFile(string);
	void generateMap(string);
	Map getCurrentMap();
private:
	Map* currentMap;
	int currentMapWidth;
	int currentMapLength;
};