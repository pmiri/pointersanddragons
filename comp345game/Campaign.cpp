#include "Campaign.h"
#include <iostream>
void Campaign::addMap(Map map)
{
	if (map.validatePath())
		mapsInCampaign.push_back(map);
	else
		std::cout << "Invalid map";
}

void Campaign::addMap(Map map, int index)
{
	if (index < mapsInCampaign.size)
		mapsInCampaign.insert(mapsInCampaign.begin() + index, map);
	else
		mapsInCampaign.push_back(map);
}

Map Campaign::getMapAt(int index)
{
	if (index < mapsInCampaign.size)
		return mapsInCampaign.at(index);
}

void Campaign::removeMap(int index)
{
	mapsInCampaign.erase(mapsInCampaign.begin() + index);
}

Campaign::Campaign(std::string campaignName)
{
	name = campaignName;
}

Campaign::Campaign(std::vector<Map> maps, std::string campaignName)
{
	name = campaignName;
	mapsInCampaign = maps;
}
