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
	static Map* buildMap(char rooms[], int width, int length);
	static Campaign* buildCampaign(Map maps[], int numberOfMaps, std::string name);
	static void saveMap(Map mapToSave, std::string filepath);
	static Map* loadMap(std::string filepath);
	static void saveCampaign(Campaign campaignToSave, std::string filepaths[]);
	static Campaign* loadCampaign(std::string filepath);
	MapCreator() {};
};