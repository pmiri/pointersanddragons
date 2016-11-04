//! @file 
//! @brief Implementation file for the Map Creator class  
//!
#pragma once
#include "Map.h"
#include "Campaign.h"
#include <string>

//! Class implementing a game map creator
class MapCreator
{
public:
	Map* buildMap(char rooms[], int width, int length);
	Campaign* buildCampaign(Map maps[], int numberOfMaps, std::string name);
	void saveMap(Map mapToSave, std::string filepath);
	Map* loadMap(std::string filepath);
	void saveCampaign(Campaign campaignToSave, std::string filepaths[]);
	Campaign* loadCampaign(std::string filepath);
private:
	Map mapInProgress;
};