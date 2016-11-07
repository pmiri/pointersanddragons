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
	std::string name;
	void addNewMap(Map map);
	void addNewMap(Map map, int index);
	Map getMapAt(int index);
	void removeMap(int index);
	void editMap(Map map, int index);
	int getSize();

	Campaign(std::string campaignName);
	Campaign(std::vector<Map> maps, std::string campaignName);
private:
	Map* mapList;
	std::vector<Map> mapsInCampaign;
	int mapCount;
};
