//! @file 
//! @brief Implementation file for the Campaign class  
//!
#include "Campaign.h"
#include <iostream>

using namespace std;

Campaign::Campaign()
{
	mapCount = 0;
	mapsInCampaign = vector<Map>();
}

Campaign::Campaign(int campaignSize)
{
	mapList = new Map[campaignSize];
	mapCount = 0;
}

void Campaign::addMap(Map m)
{
	mapList[mapCount] = m;
	mapCount++;
}

void Campaign::addNewMap(Map map)
{
	if (map.validatePath())
		mapsInCampaign.push_back(map);
	else
		std::cout << "Invalid map";
}

void Campaign::addNewMap(Map map, int index)
{
	if (index < mapsInCampaign.size())
		mapsInCampaign.insert(mapsInCampaign.begin() + index, map);
	else
		mapsInCampaign.push_back(map);
}

Map Campaign::getMapAt(int index)
{
	if (index < mapsInCampaign.size())
		return mapsInCampaign.at(index);
}

void Campaign::removeMap(int index)
{
	mapsInCampaign.erase(mapsInCampaign.begin() + index);
}

void Campaign::editMap(Map map, int index)
{
	mapsInCampaign.at(index) = map;
}

int Campaign::getSize()
{
	return mapsInCampaign.size();
}

Campaign::Campaign(std::vector<Map> maps)
{
	mapsInCampaign = vector<Map>(maps.size());
	for (int i = 0; i < maps.size(); i++)
	{
		mapsInCampaign.push_back(maps.at(i));
	}
	mapCount = maps.size();
}

Map Campaign::nextMap() {
	return currentMapIndex == mapCount? getMapAt(currentMapIndex) : getMapAt(++currentMapIndex);
}

Map Campaign::previousMap() {
	return currentMapIndex == 0 ? getMapAt(currentMapIndex) : getMapAt(--currentMapIndex);
}