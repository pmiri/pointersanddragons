//! @file 
//! @brief Implementation file for the Campaign class  
//!
#include "Campaign.h"
#include <iostream>

using namespace std;

Campaign::Campaign()
{
}

Campaign::Campaign(int campaignSize)
{
}

void Campaign::addMap(Map* map)
{
	mapsInCampaign.push_back(map);
	/*Map validator no longer works fyi @pmiri
	if (map.validatePath())
		mapsInCampaign.push_back(map);
	else
		std::cout << "Invalid map";*/
}

void Campaign::addMap(Map* map, int index)
{
	if (index < mapsInCampaign.size())
		mapsInCampaign.insert(mapsInCampaign.begin() + index, map);
	else
		mapsInCampaign.push_back(map);
}

Map* Campaign::getMapAt(int index)
{
	if (index < mapsInCampaign.size())
		return mapsInCampaign.at(index);
}

void Campaign::removeMap(int index)
{
	mapsInCampaign.erase(mapsInCampaign.begin() + index);
}

void Campaign::editMap(Map* map, int index)
{
	mapsInCampaign.at(index) = map;
}

int Campaign::getSize()
{
	return mapsInCampaign.size();
}

Campaign::Campaign(std::string campaignName)
{
	name = campaignName;
}

Campaign::Campaign(std::vector<Map*> maps, std::string campaignName)
{
	name = campaignName;
	mapsInCampaign = maps;
}

Map* Campaign::nextMap() {
	return currentMapIndex == mapsInCampaign.size()? getMapAt(currentMapIndex) : getMapAt(++currentMapIndex);
}

Map* Campaign::previousMap() {
	return currentMapIndex == 0 ? getMapAt(currentMapIndex) : getMapAt(--currentMapIndex);
}