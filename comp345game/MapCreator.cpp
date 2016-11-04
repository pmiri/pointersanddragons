#include "MapCreator.h"
#include <iostream>
#include <fstream>

Map* MapCreator::buildMap(char rooms[], int width, int length)
{
	Map* customMap = new Map(width, length);
	int roomPosition = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			customMap->fillCell(i, j, rooms[roomPosition]);
			roomPosition++;
		}
	}
	return customMap;
}

Campaign * MapCreator::buildCampaign(Map maps[], int numberOfMaps, std::string name)
{
	std::vector<Map> campaignMaps;
	for (int i = 0; i < numberOfMaps; i++)
	{
		campaignMaps.push_back(maps[i]);
	}
	Campaign* newCampaign = new Campaign(campaignMaps, name);
	return nullptr;
}

void MapCreator::saveMap(Map mapToSave, std::string filepath)
{
	char blankSpace = ' ';
	std::ofstream fileToWrite;
	fileToWrite.open(filepath);
	int width = mapToSave.getWidth();
	int length = mapToSave.getLength();
	if (fileToWrite.is_open())
	{
		fileToWrite << width << std::endl;
		fileToWrite << length << std::endl;
		for (int row = 0; row < length; row++)
		{
			for (int column = 0; column < width; column++) {
				fileToWrite << mapToSave.getCell(column, row) << blankSpace;
			}
			fileToWrite << std::endl;
			row++;
		}
		fileToWrite.close();
	}
	else
		std::cout << "Error in opening file \n";
}

Map* MapCreator::loadMap(std::string filepath)
{
	std::string currentLine = "";
	std::ifstream fileToLoad;
	int mapWidth, mapHeight;
	fileToLoad.open(filepath);
	if (fileToLoad.is_open())
	{
		//get width and height, check if the lines exist
		if (getline(fileToLoad, currentLine))
		{
			mapWidth = atoi(currentLine.c_str());
			if (getline(fileToLoad, currentLine))
				mapHeight = atoi(currentLine.c_str());
			else
				return nullptr;
		}
		else
			return nullptr;

		Map *mapFromFile = new Map(mapWidth, mapHeight);
		int row = 0;
		const char *lineFromFile;
		while (getline(fileToLoad, currentLine))
		{
			lineFromFile = currentLine.c_str();
			for (int column = 0; column < mapWidth; column++) {
				mapFromFile->fillCell(row, column, lineFromFile[2 * column]);
			}
			row++;
		}
		fileToLoad.close();
		return mapFromFile;
	}
	else
		std::cout << "Error in opening file \n";
	return nullptr;
}

void MapCreator::saveCampaign(Campaign campaignToSave, std::string filepaths[])
{
	std::string currentLine = "";
	std::ofstream fileToWrite;
	fileToWrite.open(filepaths[0]);
	if (fileToWrite.is_open())
	{
		fileToWrite << campaignToSave.name << std::endl;
		int numberOfMaps = campaignToSave.getSize();
		fileToWrite << numberOfMaps << std::endl;
		for (int i = 0; i < numberOfMaps; i++)
		{
			fileToWrite << filepaths[i + 1] << std::endl;
			saveMap(campaignToSave.getMapAt(i), filepaths[i + 1]);
		}
		fileToWrite.close();
	}
	else
		std::cout << "Error in opening file \n";
}

Campaign* MapCreator::loadCampaign(std::string filepath)
{
	std::string currentLine = "";
	std::ifstream fileToLoad;
	fileToLoad.open(filepath);
	if (fileToLoad.is_open())
	{
		if (!getline(fileToLoad, currentLine))
			return nullptr;
		else
		{
			Campaign* campaignFromFile = new Campaign(currentLine);
			if (!getline(fileToLoad, currentLine))
				return nullptr;
			else
			{
				int numberOfMaps = atoi(currentLine.c_str());
				for (int i = 0; i < numberOfMaps; i++)
				{
					if (getline(fileToLoad, currentLine))
					{
						Map tempMap = *loadMap(currentLine);
						campaignFromFile->addMap(tempMap);
					}
					else
						return nullptr;
				}
			}
			fileToLoad.close();
			return campaignFromFile;
		}
	}
	else
		std::cout << "Error in opening file \n";
	return nullptr;
}
