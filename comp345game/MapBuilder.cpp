#include "MapBuilder.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
using namespace std;

Map *MapBuilder::buildFromFile(string path) {
	string line = "";
	ifstream myfile;
	int width;
	int height;
	myfile.open(path);
	if (myfile.is_open())
	{
		//get width
		if (getline(myfile, line))
			width = atoi(line.c_str());
		else return nullptr;
		//get height
		if (getline(myfile, line))
			height = atoi(line.c_str());
		else return nullptr;

		Map *map = new Map(width, height);

		int currentHeight = 0;
		const char *line_array;
		while (getline(myfile, line))
		{
			line_array = line.c_str();
			for (int y = 0; y < width; y++) {
				if (line_array[2 * y] == 'P') {
					//create a character who is a player
					Character* playerCharacter = new Character;//TODO pull player character info from map somehow?
					MapObject characterMapObject = MapObject(y, currentHeight, line_array[2 * y]);
					characterMapObject.setCharacter(playerCharacter);
					map->fillCell(y, currentHeight, characterMapObject);
				}
				if (line_array[2 * y] == 'M') {
					//create a character who is a player
					Character* playerCharacter = new Character;//TODO pull monster character info from map somehow?
					playerCharacter->isPlayer = 'M';
					MapObject characterMapObject = MapObject(y, currentHeight, line_array[2 * y]);
					characterMapObject.setCharacter(playerCharacter);
					map->fillCell(y, currentHeight, characterMapObject);
				}
				else if (line_array[2 * y] == 'T') {
					//create a character who is a player
					ItemContainer* items = new ItemContainer;
					items->addItem(Item());//TODO pull item info from map somehow?
					MapObject itemMapObject = MapObject(y, currentHeight, line_array[2 * y]);
					itemMapObject.setItem(items->getItems());
					map->fillCell(y, currentHeight, itemMapObject);
				}
				else {
					map->fillCell(y, currentHeight, MapObject(y, currentHeight, line_array[2 * y]));
				}
				//cout << map->getCell(y, currentHeight);
			}
			currentHeight++;
			//do stuff to build map
			//cout << line << endl;
		}
		myfile.close();
		return map;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
}

Map *MapBuilder::buildFromMap(Map map) {
	return nullptr;
}