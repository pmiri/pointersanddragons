//! @file 
//! @brief Implementation file for the Map Creator class  
//!
#pragma once
#include "Map.h"
#include <string>
#include <vector>

//! Class implementing a game map creator
class Campaign
{
public:
	std::string name;
	void addMap(Map map);
	void addMap(Map map, int index);
	Map getMapAt(int index);
	void removeMap(int index);
	int getSize();

	Campaign(std::string campaignName);
	Campaign(std::vector<Map> maps, std::string campaignName);
private:
	std::vector<Map> mapsInCampaign;
};