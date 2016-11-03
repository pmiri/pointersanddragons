#include "MapCreator.h"
#include <iostream>
#include <fstream>

Map* MapCreator::buildMap(char rooms[], int width, int length)
{
	return &Map();
}

void MapCreator::saveMap(Map mapToSave, std::string filepath, int width, int height)
{
	char blankSpace = ' ';
	std::ofstream fileToWrite;
	fileToWrite.open(filepath);
	if (fileToWrite.is_open())
	{
		fileToWrite << width << std::endl;
		fileToWrite << height << std::endl;
		for (int row = 0; row < height; row++)
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
