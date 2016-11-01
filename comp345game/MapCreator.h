//! @file 
//! @brief Implementation file for the Map Creator class  
//!
#pragma once
#include "Map.h"
#include <string>

//! Class implementing a game map creator
class MapCreator
{
public:
	Map buildMap(char rooms[], int width, int length);
	void saveMap(Map mapToSave);
	Map loadMap(std::string filepath);

private:
	Map mapInProgress;
};