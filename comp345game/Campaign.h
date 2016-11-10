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
	void addMap(Map);
	string name;
	void addNewMap(Map map);
	void addNewMap(Map map, int index);
	Map getMapAt(int index);
	Map nextMap();
	Map previousMap();
	void removeMap(int index);
	void editMap(Map map, int index);
	int getSize();

	Campaign(string campaignName);
	Campaign(vector<Map> maps, string campaignName);
private:
	Map* mapList;
	vector<Map> mapsInCampaign;
	int mapCount;
	int currentMapIndex = 0;
};
