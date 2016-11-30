//! @file 
//! @brief Implementation file for the Map Creator class  
//! The map creator has no domain representation.
//! This only exists to make maps and campaigns
#pragma once
#include "Map.h"
#include "Campaign.h"
#include <string>
#include "FileLoader.h"
#include "MapBuilder.h"

//! Class implementing a game map creator
class MapCreator
{
public:
	static void runMenu();
	static Map* buildMap(char rooms[], int width, int length);
	static Map* buildMap(int width, int length);
	static Campaign* buildCampaign(Map maps[], int numberOfMaps);
	static Campaign* buildCampaign(int numberOfMaps);
	static void saveMap(Map mapToSave, std::string filepath);
	static void saveMap(Map *mapToSave);
	static Map* loadMap(std::string filepath);
	static Map* loadMap();
	static Map* editMap(Map* maptoEdit);
	static void saveCampaign(Campaign *campaignToSave, std::string filepaths[]);
	static void saveCampaign(Campaign *campaignToSave);
	static void loadCampaign(std::string filepath, Campaign *campaignToEdit);
	static Campaign* loadCampaign(std::string filepath);
	static Campaign* loadCampaign();
	static Campaign* editCampaign(Campaign *campaignToEdit);
	static int getHeight();
	static int getWidth();
	static int getNumberOfMaps();
	static int getRow(int maxRow);
	static int getColumn(int maxCol);
	static int getMapIndex(int maxIndex);
	static char getTile();
	static void viewMap(Map *map);
	static void printMapDetails(Map *map);
	static void setNext(Map *maptoEdit);
	static void setPrev(Map *maptoEdit);
	MapCreator() {};
};