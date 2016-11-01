#include "MapBuilder.h"
#include <iostream>
#include <fstream>
#include <string>
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
				map->fillCell(y,currentHeight, line_array[2 * y]);
				cout << map->getCell(y, currentHeight);
			}

			//do stuff to build map
			cout << line << endl;
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

