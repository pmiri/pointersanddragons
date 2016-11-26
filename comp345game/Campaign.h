//! @file 
//! @brief Implementation file for the Campaign class  
//! The Campaign class contains th order inwhich mapsare traversed
//!
#pragma once

using namespace std;
#include "Map.h"
#include <string>
#include <vector>
class Campaign
{
public:
	Campaign();
	Campaign(int);
	string name;
	void addMap(Map*);
	void addMap(Map*, int);
	Map* getMapAt(int);
	Map* nextMap();
	Map* previousMap();
	void removeMap(int);
	void editMap(Map*, int);
	int getSize();

	Campaign(string);
	Campaign(vector<Map*>, string);
private:
	vector<Map*> mapsInCampaign;
	int currentMapIndex = 0;
};
