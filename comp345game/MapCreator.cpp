#include "MapCreator.h"
#include <iostream>
#include <fstream>
#include <string>

Map* MapCreator::buildMap(char rooms[], int width, int length)
{
	return &Map();
}

void MapCreator::saveMap(Map mapToSave)
{
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
