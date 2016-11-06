//! @file 
//! @brief Implementation file for the Campaign class  
//! Campaigns are made of maps, one connecting to the other
//! Maps are connected to the map before and after them
#pragma once
#include "Map.h"
#include <string>
#include <vector>

//! Class implementing a campaign
class Campaign
{
public:
	std::string name;
	void addMap(Map map);
	void addMap(Map map, int index);
	Map getMapAt(int index);
	void removeMap(int index);
	void editMap(Map map, int index);
	int getSize();

	Campaign(std::string campaignName);
	Campaign(std::vector<Map> maps, std::string campaignName);
private:
	std::vector<Map> mapsInCampaign;
};