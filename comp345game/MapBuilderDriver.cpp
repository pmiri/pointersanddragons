#include <iostream>
#include "Map.h"
#include "MapBuilder.h"



int main() {
	string path = "myFile.txt";
	Map *map = MapBuilder::buildFromFile(path);

	cout << map->getCell(2, 2) << endl;

	delete map;

	return 0;
}

