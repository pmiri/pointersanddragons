//! @file 
//! @brief Implementation file for the Campaign class  
//! The Campaign class contains the order in which maps are traversed
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
	void addMap(Map);
	void addNewMap(Map);
	void addNewMap(Map, int);
	Map getMapAt(int);
	Map nextMap();
	Map previousMap();
	void removeMap(int);
	void editMap(Map, int);
	int getSize();
	Campaign(vector<Map>);
private:
	Map* mapList;
	vector<Map> mapsInCampaign;
	int mapCount;
	int currentMapIndex = 0;
};
