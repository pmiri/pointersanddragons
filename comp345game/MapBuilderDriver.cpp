#include <iostream>
#include "Map.h"
#include "MapBuilder.h"



int main() {
	string path = "myFile.txt";
	Map *map = MapBuilder::buildFromFile(path);

	char x = map->getCell(0, 1);
	cout << x << endl;

	delete map;

	return 0;
}

