//! @file 
//! @brief Implementation file for the MapEditor class  
//!
#include "MapEditor.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MapEditor::MapEditor()
{

}

MapEditor::MapEditor(string fileName)
{
	loadMapFromFile(fileName);
}

void MapEditor::loadMapFromFile(string fileName)
{
	if (validMapFile(fileName))
		generateMap(fileName);
}

bool MapEditor::validMapFile(string fileName)
{
	ifstream mapFile;
	mapFile.open(fileName);
	//check for prescence of illegal characters in the map file
	string line;
	int width = 0;
	int length = 0;
	while (getline(mapFile, line))
	{
		//the map file is invalid if an illegal character is found
		if (line.find_first_not_of("WCMBTE ") != std::string::npos)
		{
			mapFile.close();
			cout << "Invalid map file " << fileName << ": illegal character found\n";
			return false;
		}
		//map width is as wide as the map file's longest line
		if (line.length() > width)
			width = line.length();
		length++;
	}

	currentMapLength = length;
	currentMapWidth = width;

	mapFile.close();
	return true;
}

void MapEditor::generateMap(string fileName)
{
	ifstream mapFile;
	mapFile.open(fileName);

	string line;
	currentMap = new Map(currentMapWidth, currentMapLength);

	//fill the map's cells with the (valid) map file's content
	int row = 0;
	while(getline(mapFile, line))
	{
		for (int column = 0; column < line.length(); column++)
		{
			currentMap->fillCell(row, column, line[column]);
		}
		row++;
	}

	mapFile.close();

	if (!currentMap->validatePath())
		cout << "Invalid map file " << fileName << ": no valid path from entrance to exit\n";
}

Map MapEditor::getCurrentMap()
{
	return *currentMap;
}

//int main() {
//	MapEditor* editor = new MapEditor("Maps/test.txt");
//	delete editor;
//	system("pause");
//	return 0;
//}
