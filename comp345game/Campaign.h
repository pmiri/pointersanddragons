//! @file 
//! @brief Implementation file for the Campaign class  
//! The Campaign class contains th order inwhich mapsare traversed
//!
#pragma once

using namespace std;
#include "Map.h"

class Campaign
{
public:
	Campaign();
	Campaign(int);
	void addMap(Map);
private:
	Map* mapList;
	int mapCount;
};
