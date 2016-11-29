#include "MapCreator.h"
#include <iostream>
#include <fstream>

void MapCreator::runMenu()
{
	std::string userInput = "";
	bool running = true;
	const string MAPS_PATH = "../maps/";
	const string CHARACTERS_PATH = "../characters/";
	while (running)
	{
		std::cout << "Welcome to the Map and Campaign Creating and Editing Tool!" << std::endl << "Would you like to load a map or camapign (l), create a new one (n), or quit (q)?" << std::endl;
		std::cin >> userInput;
		if (userInput == "(l)" || userInput == "l" || userInput == "L" || userInput == "(L)")
		{
			std::cout << "Welcome to the Map and Campaign Editor!" << std::endl << "Would you like to edit a map (m) or a campaign (c)?" << std::endl;
			std::cin >> userInput;
			if (userInput == "(m)" || userInput == "m" || userInput == "M" || userInput == "(M)")
			{
				Map* loadedMap = MapBuilder::buildFromFile(FileLoader::mapSelection());
				std::cout << "Here is the loaded map!" << std::endl;
				MapCreator::viewMap(loadedMap);
				MapCreator::editMap(loadedMap);
				std::cout << "Would you like to save the edited map (y) or not (n)?" << std::endl;
				std::cin >> userInput;
				if (userInput == "(y)" || userInput == "y" || userInput == "Y" || userInput == "(Y)")
				{
					MapCreator::saveMap(loadedMap);
				}
				else
				{
					std::cout << "Map discarded. Returning to menu!" << std::endl;
				}
			}
			else if (userInput == "(c)" || userInput == "c" || userInput == "C" || userInput == "(C)")
			{
				std::cout << "Please select a saved campaign." << std::endl;
				Campaign *loadedCampaign = MapCreator::loadCampaign(FileLoader::campaignSelection());
				std::cout << "Here is the loaded campaign!" << std::endl;
				std::cout << "The campaign has " << loadedCampaign->getSize() << " maps in it" << std::endl;
				for (int i = 0; i < loadedCampaign->getSize(); i++)
				{
					std::cout << "Map number " << i << ": ";
					printMapDetails(loadedCampaign->getMapAt(i));
				}
				MapCreator::editCampaign(loadedCampaign);
				std::cout << "Would you like to save the edited campaign (y) or not (n)?" << std::endl;
				std::cin >> userInput;
				if (userInput == "(y)" || userInput == "y" || userInput == "Y" || userInput == "(Y)")
				{
					MapCreator::saveCampaign(loadedCampaign);
				}
				else
				{
					std::cout << "Campaign discarded. Returning to menu!" << std::endl;
				}
			}
			else
				std::cout << "I didn't understand that, sorry!" << std::endl;
		}
		else if (userInput == "(n)" || userInput == "n" || userInput == "N" || userInput == "(N)")
		{
			std::cout << "Welcome to the Map and Campaign Creator!" << std::endl << "Would you like to make a map (m) or a campaign (c)?" << std::endl;
			std::cin >> userInput;
			if (userInput == "(m)" || userInput == "m" || userInput == "M" || userInput == "(M)")
			{
				int length;
				int width;
				length = MapCreator::getHeight();
				width = MapCreator::getWidth();
				Map *customMap = MapCreator::buildMap(length, width);
				std::cout << "Here is the finished map!" << std::endl;
				MapCreator::viewMap(customMap);
				std::cout << "Would you like to save the map (y) or not (n)?" << std::endl;
				std::cin >> userInput;
				if (userInput == "(y)" || userInput == "y" || userInput == "Y" || userInput == "(Y)")
				{
					MapCreator::saveMap(customMap);
				}
				else
				{
					std::cout << "Map discarded. Returning to menu!" << std::endl;
				}
			}
			else if (userInput == "(c)" || userInput == "c" || userInput == "C" || userInput == "(C)")
			{
				int numberOfMaps;
				numberOfMaps = MapCreator::getNumberOfMaps();
				Campaign *customCampaign = MapCreator::buildCampaign(numberOfMaps);
				std::cout << "Here is the finished campaign!" << std::endl;
				std::cout << "The campaign has " << customCampaign->getSize() << " maps in it" << std::endl;
				for (int i = 0; i < customCampaign->getSize(); i++)
				{
					std::cout << "Map number " << i << ": ";
					printMapDetails(customCampaign->getMapAt(i));
				}
				std::cout << "Would you like to save the campaign (y) or not (n)?" << std::endl;
				std::cin >> userInput;
				if (userInput == "(y)" || userInput == "y" || userInput == "Y" || userInput == "(Y)")
				{
					MapCreator::saveCampaign(customCampaign);
				}
				else
				{
					std::cout << "Campaign discarded. Returning to menu!" << std::endl;
				}
			}
			else
				std::cout << "I didn't understand that, sorry!" << std::endl;
		}
		else if (userInput == "(q)" || userInput == "q" || userInput == "Q" || userInput == "(Q)")
		{
			std::cout << "Goodbye!" << std::endl;
			running = false;
		}
		else
			std::cout << "I didn't understand that, sorry!" << std::endl;
	}
}

Map* MapCreator::buildMap(char rooms[], int width, int length)
{
	Map* customMap = new Map(width, length);
	int roomPosition = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			customMap->fillCell(i, j, MapObject(i,j, rooms[roomPosition]));
			roomPosition++;
		}
	}
	return customMap;
}

Map * MapCreator::buildMap(int length, int width)
{
	Map* customMap = new Map(width, length);
	std::string userInput = "";
	for (int currentRow = 0; currentRow < length; currentRow++)
	{
		for (int currentColumn = 0; currentColumn < width; currentColumn++)
		{
			std::cout << "Please input the desired tile for the tile at row " << currentRow << " and column " << currentColumn << ".\n";
			char result = MapCreator::getTile();
			customMap->fillCell(currentColumn, currentRow, MapObject(currentColumn, currentRow, result));
		}
		if (currentRow < (length - 1))
		{
			std::cout << "Would you like to view the map (v)?.\n";
			std::cin >> userInput;
			if (userInput == "V" || userInput == "v" || userInput == "(v)" || userInput == "(V)")
			{
				std::cout << "Here is the map so far!\n";
				MapCreator::viewMap(customMap);
			}
		}
	}
	return customMap;
}

Campaign *MapCreator::buildCampaign(Map maps[], int numberOfMaps)
{
	std::vector<Map> campaignMaps;
	for (int i = 0; i < numberOfMaps; i++)
	{
		campaignMaps.push_back(maps[i]);
	}
	Campaign* newCampaign = new Campaign(campaignMaps);
	return newCampaign;
}

Campaign *MapCreator::buildCampaign(int numberOfMaps)
{
	std::vector<Map> campaignMaps;
	for (int i = 0; i < numberOfMaps; i++)
	{
		Map tempMap = *MapCreator::loadMap();
		campaignMaps.push_back(tempMap);
	}
	Campaign* newCampaign = new Campaign(campaignMaps);
	return newCampaign;
}

void MapCreator::saveMap(Map mapToSave, std::string filepath)
{
	const string MAPS_PATH = "../maps/";
	if (mapToSave.validatePath())
	{
		char blankSpace = ' ';
		std::ofstream fileToWrite;
		fileToWrite.open((MAPS_PATH + filepath), std::ifstream::out | std::ifstream::trunc);
		fileToWrite.clear();
		int width = mapToSave.getWidth();
		int length = mapToSave.getHeight();
		if (fileToWrite.is_open())
		{
			fileToWrite << width << std::endl;
			fileToWrite << length << std::endl;
			for (int column = 0; column < width; column++) {
				for (int row = 0; row < length; row++)
				{
					fileToWrite << mapToSave.getCell(column, row) << blankSpace;
				}
				fileToWrite << std::endl;
			}
			fileToWrite.close();
			std::cout << "Map Saved!\n";
		}
		else
			std::cout << "Error in opening file.\n";
	}
	else
	{
		std::cout << "Error: Map is invalid.\n";
	}
}

void MapCreator::saveMap(Map *mapToSave)
{
	const string MAPS_PATH = "../maps/";
	if (mapToSave->validatePath())
	{
		char blankSpace = ' ';
		std::string filePath;
		std::ofstream fileToWrite;
		fileToWrite.exceptions(std::ofstream::failbit | std::ofstream::badbit);
		bool invalidInput = false;
		do
		{
			std::cout << "Where would you like the file saved?" << std::endl;
			std::cin >> filePath;
			try {
				fileToWrite.open((MAPS_PATH + filePath), std::ifstream::out | std::ifstream::trunc);
				fileToWrite.clear();
				invalidInput = false;
			}
			catch (const std::ofstream::failure& e) {
				std::cout << "Could not open file\n";
				invalidInput = true;
			}
		} while (invalidInput);
		int width = mapToSave->getWidth();
		int length = mapToSave->getHeight();
		if (fileToWrite.is_open())
		{
			fileToWrite << width << std::endl;
			fileToWrite << length << std::endl;

			for (int row = 0; row < length; row++) {
				for (int column = 0; column < width; column++)
				{
					fileToWrite << mapToSave->getCell(column, row) << blankSpace;
				}
				fileToWrite << std::endl;
			}
			fileToWrite.close();
			std::cout << "Map Saved!\n";
		}
		else
			std::cout << "Error in opening file \n";
	}
	else
		std::cout << "Error: Map is invalid.\n";
}

Map* MapCreator::loadMap(std::string filepath)
{
	const string MAPS_PATH = "../maps/";
	std::string currentLine = "";
	std::ifstream fileToLoad;
	int mapWidth, mapHeight;
	fileToLoad.open(MAPS_PATH + filepath);
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
				mapFromFile->fillCell(row, column, MapObject(row, column, lineFromFile[2 * column]));
			}
			row++;
		}
		fileToLoad.close();
		if (mapFromFile->validatePath())
			return mapFromFile;
		else
		{
			std::cout << "Error: Map is invalid.\n";
			return nullptr;
		}
	}
	else
		std::cout << "Error in opening file \n";
	return nullptr;
}

Map *MapCreator::loadMap()
{
	std::string currentLine = "";
	std::ifstream fileToLoad;
	int mapWidth, mapHeight;
	std::string filePath = "";
	bool invalidInput = false;
	do
	{
		std::cout << "Which file would you like to load?" << std::endl;
		std::cin >> filePath;
		try {
			fileToLoad.open(filePath);
			invalidInput = false;
		}
		catch (const std::ofstream::failure& e) {
			std::cout << "Could not open file\n";
			invalidInput = true;
		}
	} while (invalidInput);
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
				mapFromFile->fillCell(row, column, MapObject(row, column, lineFromFile[2 * column]));
			}
			row++;
		}
		fileToLoad.close();
		if (mapFromFile->validatePath())
			return mapFromFile;
		else
		{
			std::cout << "Error: Map is invalid.\n";
			return nullptr;
		}
	}
	else
		std::cout << "Error in opening file \n";
	return nullptr;
}

Map *MapCreator::editMap(Map* mapToEdit)
{
	bool running = true;
	int length, width;
	length = mapToEdit->getHeight();
	width = mapToEdit->getWidth();
	int row, column;
	std::string userInput;
	while (running)
	{
		row = MapCreator::getRow(length);
		column = MapCreator::getColumn(width);
		std::cout << "Please input the desired tile for the tile at row " << row << " and column " << column << ".\n";
		char tile = MapCreator::getTile();
		mapToEdit->fillCell(column, row, MapObject(column, row, tile));
		std::cout << "Would you like to view the map (v)?.\n";
		std::cin >> userInput;
		if (userInput == "V" || userInput == "v" || userInput == "(v)" || userInput == "(V)")
		{
			std::cout << "Here is the map so far!\n";
			MapCreator::viewMap(mapToEdit);
		}
		std::cout << "Are you finished editing? (Press y or q to stop editing).\n";
		std::cin >> userInput;
		if (userInput == "Y" || userInput == "y" || userInput == "q" || userInput == "Q")
		{
			std::cout << "Exiting editor!.\n";
			running = false;
		}
	}
	return mapToEdit;
}

void MapCreator::saveCampaign(Campaign *campaignToSave, std::string filepaths[])
{
	bool allMapsValid = true;
	for (int i = 0; i < campaignToSave->getSize(); i++)
	{
		if (!campaignToSave->getMapAt(i).validatePath())
		{
			std::cout << "Map # " << i << " is invalid! Aborting save.\n";
			allMapsValid = false;
		}
	}
	if (allMapsValid)
	{
		std::string currentLine = "";
		for (int i = 0; i < campaignToSave->getSize(); i++){
				saveMap(campaignToSave->getMapAt(i), filepaths[i]);
		}
			std::cout << "Campaign Saved!\n";
	}
}

void MapCreator::saveCampaign(Campaign *campaignToSave)
{
	bool allMapsValid = true;
	for (int i = 0; i < campaignToSave->getSize(); i++)
	{
		if (!campaignToSave->getMapAt(i).validatePath())
		{
			std::cout << "Map # " << i << " is invalid! Aborting save.\n";
			allMapsValid = false;
		}
	}
	if (allMapsValid)
	{
		for (int i = 0; i < campaignToSave->getSize(); i++)
			{
				string filePath = "";
				std::cout << "Please enter the filename you wish to use for map #" << (i + 1) << std::endl;
				std::cin >> filePath;
				saveMap(campaignToSave->getMapAt(i), filePath);
			}
			std::cout << "Campaign Saved!\n";
	}
}

Campaign* MapCreator::loadCampaign(std::string filepath)
{
	bool hasNext = true;
	string currentPath = filepath;
	Campaign *loadedCampaign = new Campaign();;
	vector<Map> maps;
	int i = 0;
	while (hasNext)
	{
		maps.push_back(*loadMap(currentPath));
		currentPath = maps.at(i).next;
		if (currentPath == "")
			hasNext = false;
		else
			i++;
	}
	*loadedCampaign = Campaign(maps);
	return loadedCampaign;
}

Campaign *MapCreator::loadCampaign()
{
	bool invalidInput = false;
	string currentPath;
	std::cout << "Which file would you like to load?" << std::endl;
	std::cin >> currentPath;
	bool hasNext = true;
	Campaign *loadedCampaign = new Campaign();
	vector<Map> maps;
	int i = 0;
	while (hasNext)
	{
		maps.push_back(*loadMap(currentPath));
		currentPath = maps.at(i).next;
		if (currentPath == "")
			hasNext = false;
		else
			i++;
	}
	*loadedCampaign = Campaign(maps);
	return loadedCampaign;
}

Campaign *MapCreator::editCampaign(Campaign *campaignToEdit)
{
	bool running = true;
	std::string userInput;
	while (running)
	{
		std::cout << "Would you like to edit campaign details (c) or one of the maps (m)?\n";
		std::cin >> userInput;
		if (userInput == "(c)" || userInput == "(C)" || userInput == "c" || userInput == "C")
		{
			std::cout << "Would you like to add a map (a), view a map (v), or remove a map (r)?\n";
			std::cin >> userInput;
			if (userInput == "(a)" || userInput == "(A)" || userInput == "a" || userInput == "A")
			{
				std::cout << "Please select a map to load.\n";
				campaignToEdit->addMap(*MapCreator::loadMap());
				std::cout << "Map added! Current campaign size is now " << campaignToEdit->getSize() << ".\n";
			}
			else if (userInput == "(v)" || userInput == "(V)" || userInput == "v" || userInput == "V")
			{
				std::cout << "Please select a map to view.\n";
				int index = MapCreator::getMapIndex(campaignToEdit->getSize());
				std::cout << "Here is map #" << index << "!\n";
				MapCreator::viewMap(&campaignToEdit->getMapAt(index));
			}
			else if (userInput == "(r)" || userInput == "(R)" || userInput == "r" || userInput == "R")
			{
				std::cout << "Please select a map to remove.\n";
				for (int i = 0; i < campaignToEdit->getSize(); i++)
				{
					std::cout << "Map number " << i << ": ";
					printMapDetails(campaignToEdit->getMapAt(i));
				}
				int index = MapCreator::getMapIndex(campaignToEdit->getSize());
				campaignToEdit->removeMap(index);
			}
			else
			{
				std::cout << "Sorry! I didn't understand!\n";
			}
		}
		else if (userInput == "(m)" || userInput == "(M)" || userInput == "m" || userInput == "M")
		{
			int index = MapCreator::getMapIndex(campaignToEdit->getSize());
			campaignToEdit->editMap(*MapCreator::editMap(&campaignToEdit->getMapAt(index)), index);
		}
		else
		{
			std::cout << "Sorry! I didn't understand!\n";
		}
		std::cout << "Are you finished editing? (Press y or q to stop editing).\n";
		std::cin >> userInput;
		if (userInput == "Y" || userInput == "y" || userInput == "q" || userInput == "Q")
		{
			std::cout << "Exiting editor!.\n";
			running = false;
		}
	}
	return campaignToEdit;
}

int MapCreator::getHeight()
{
	int length;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "How tall should the map be?" << std::endl;
		std::cin >> userInput;
		length = atoi(userInput.c_str());
		if (length < 1 | length > 100)
		{
			std::cout << "Let's be reasonable, here!" << std::endl;
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
			std::cout << "The map will be " << length << " tiles tall" << std::endl;
		}
	} while (invalidInput);
	return length;
}

int MapCreator::getWidth()
{
	int width;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "How wide should the map be?" << std::endl;
		std::cin >> userInput;
		width = atoi(userInput.c_str());
		if (width < 1 | width > 100)
		{
			std::cout << "Let's be reasonable, here!" << std::endl;
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
			std::cout << "The map will be " << width << " tiles wide" << std::endl;
		}
	} while (invalidInput);
	return width;
}

int MapCreator::getNumberOfMaps()
{
	int numberOfMaps;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "How many maps will be in the campaign?" << std::endl;
		std::cin >> userInput;
		numberOfMaps = atoi(userInput.c_str());
		if (numberOfMaps < 1 | numberOfMaps > 100)
		{
			std::cout << "Let's be reasonable, here!" << std::endl;
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
			std::cout << "The campaign will have " << numberOfMaps << " maps" << std::endl;
		}
	} while (invalidInput);
	return numberOfMaps;
}

int MapCreator::getRow(int maxRow)
{
	int row;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "Please input row of cell you wish to edit. (Number of rows : " << maxRow << ".)\n";
		std::cin >> userInput;
		row = atoi(userInput.c_str());
		if (row < 0 || row > maxRow)
		{
			std::cout << "That number is out of range. Please insert a number between 0-" << maxRow << ".\n";
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
		}
	} while (invalidInput);
	return row;
}

int MapCreator::getColumn(int maxCol)
{
	int col;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "Please input the column of cell you wish to edit. (Number of columns : " << maxCol << ".)\n";
		std::cin >> userInput;
		col = atoi(userInput.c_str());
		if (col < 0 || col > maxCol)
		{
			std::cout << "That number is out of range. Please insert a number between 0-" << maxCol << ".\n";
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
		}
	} while (invalidInput);
	return col;
}

int MapCreator::getMapIndex(int maxIndex)
{
	int index;
	std::string userInput = "";
	bool invalidInput = false;
	do
	{
		std::cout << "Please input index of the map you wish to edit. (Number of maps : " << maxIndex << ".)\n";
		std::cin >> userInput;
		index = atoi(userInput.c_str());
		if (index < 0 || index > maxIndex)
		{
			std::cout << "That number is out of range. Please insert a number between 0-" << maxIndex << ".\n";
			invalidInput = true;
		}
		else
		{
			invalidInput = false;
		}
	} while (invalidInput);
	return index;
}

char MapCreator::getTile()
{
	bool invalidInput = false;
	std::string userInput;
	do
	{
		std::cin >> userInput;
		if (userInput == "W" || userInput == "w" || userInput == "(w)" || userInput == "(W)")
		{
			invalidInput = false;
			return 'W';
		}
		else if (userInput == "E" || userInput == "e" || userInput == "(e)" || userInput == "(E)")
		{
			invalidInput = false;
			return 'E';
		}
		else if (userInput == "B" || userInput == "b" || userInput == "(b)" || userInput == "(B)")
		{
			invalidInput = false;
			return 'B';
		}
		else if (userInput == "M" || userInput == "m" || userInput == "(m)" || userInput == "(M)")
		{
			invalidInput = false;
			return 'M';
		}
		else if (userInput == "F" || userInput == "f" || userInput == "(f)" || userInput == "(F)")
		{
			invalidInput = false;
			return 'F';
		}
		else if (userInput == "T" || userInput == "t" || userInput == "(t)" || userInput == "(T)")
		{
			invalidInput = false;
			return 'B';
		}
		else if (userInput == "_" || userInput == "(_)")
		{
			invalidInput = false;
			return ' ';
		}
		else
		{
			std::cout << "Invalid input. Valid characters are wall (W), empty (_), begin (B), end (E), monster (M), friendly character (F), and treasure(T)." << std::endl;
			invalidInput = true;
		}
	} while (invalidInput);
}

void MapCreator::viewMap(Map *map)
{
	int height = map->getHeight();
	int width = map->getWidth();
	for (int i = 0; i < height; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < width; j++)
		{
			std::cout << map->getCell(j, i) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "  ";
	for (int j = 0; j < width; j++)
	{
		std::cout << j << " ";
	}
	std::cout << std::endl;
}

void MapCreator::printMapDetails(Map map)
{
	std::cout << map.path << " has a height of " << map.getHeight() << " tiles and a width of " << map.getWidth() << "tiles.\n";
}
