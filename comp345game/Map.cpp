//! @file 
//! @brief Implementation file for the Map class  
//!
#include "Map.h"
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

//! constant for map length
int MAP_LENGTH = 2;
//! constant for map width
int MAP_WIDTH = 2;
//! map as a 2-dimensional array of chars
MapObject **map;

Map::Map() {
	delete[] map;

	map = new MapObject*[MAP_LENGTH];
	for (int i = 0; i < MAP_LENGTH; i++) {
		map[i] = new MapObject[MAP_WIDTH];
		for (int j = 0; j < MAP_WIDTH; j++) {
			map[i][j] = MapObject(i, j);//creates a new empty MapObject
			map[i][j].setWallOrOtherChar(' ');
		}
	}
}

Map::Map(int width, int height) {
	//clear exisiting thing
	delete[] map;
	MAP_LENGTH = height;
	MAP_WIDTH = width;

	map = new MapObject*[height];//new char*[height];
	for (int i = 0; i < height; i++)
		map[i] = new MapObject[width];//new char[width];
}

void Map::moveCharacter(char dir)
{
	int newXPosition = PlayerPositionX;
	int newYPosition = PlayerPositionY;
	char targetCellContent = ' ';

	switch (toupper(dir)) {
	case 'W':
		if (PlayerPositionY + 1 < MAP_LENGTH)//valid up move
		{
			newYPosition = PlayerPositionY + 1;
		}
		break;
	case 'A':
		if (PlayerPositionX - 1 >= 0)//valid left move
		{
			newXPosition = PlayerPositionX - 1;
		}
		break;
	case 'S':
		if (PlayerPositionY - 1 >= 0)//valid down move
		{
			newYPosition = PlayerPositionY - 1;
		}
		break;
	case 'D':
		if (PlayerPositionX + 1 < MAP_WIDTH)//valid right move
		{
			newXPosition = PlayerPositionX + 1;
		}
		break;
	default:
		cout << "no move" << endl;
		break;
	}
	targetCellContent = getCell(newXPosition, newYPosition);
	if (targetCellContent == 'W' || targetCellContent == 'M') {
		cout << endl << "That move is invalid!" << endl;//the move is invalid
		return;
	}
	map[newXPosition][newYPosition].setCharacter(map[PlayerPositionX][PlayerPositionY].getCharacter());
	map[PlayerPositionX][PlayerPositionY].setCharacter(nullptr);
	Notify();
}

//! Implementation of the map verification
//! @return bool value, true of the map is valid (there is at least one clear path between the mandatory begin and end cell). 
bool Map::validatePath()
{
	int entry_location_x = -1;
	int entry_location_y = -1;

	//search for entrance
	for (int i = 0; i < MAP_LENGTH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if ((map[i][j].wallOrOtherChar) == Map::BEGIN) {
				entry_location_x = i;
				entry_location_y = j;
				break;
			}
		}
	}

	// if no entrance, no possible path
	if (entry_location_x == -1 || entry_location_y == -1) return false;

	// BFS search for path
	// initialize all tiles as unvisited
	bool *visited = new bool[MAP_LENGTH*MAP_WIDTH];
	for (int i = 0; i < MAP_LENGTH*MAP_WIDTH; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and queue it
	visited[entry_location_x * MAP_LENGTH + entry_location_y] = true;
	queue.push_back(entry_location_x * MAP_LENGTH + entry_location_y);

	int current;
	int neighbours[4]; // up, down, left, right

	while (!queue.empty())
	{
		// Dequeue tile
		current = queue.front();

		// calculate neighbours
		neighbours[0] = ((int)(current / MAP_WIDTH) + 1) * MAP_WIDTH + current%MAP_WIDTH; // up
		neighbours[1] = ((int)(current / MAP_WIDTH) - 1) * MAP_WIDTH + current%MAP_WIDTH; // down
		neighbours[2] = (int)(current / MAP_WIDTH) * MAP_WIDTH + current%MAP_WIDTH - 1; // left
		neighbours[3] = (int)(current / MAP_WIDTH) * MAP_WIDTH + current%MAP_WIDTH + 1; // right

																						//edge cases
		neighbours[0] = neighbours[0] > MAP_LENGTH * MAP_WIDTH ? -1 : neighbours[0];
		neighbours[1] = neighbours[1] < MAP_LENGTH * MAP_WIDTH ? -1 : neighbours[1];
		neighbours[2] = neighbours[2] < MAP_LENGTH * MAP_WIDTH ? -1 : neighbours[2];
		neighbours[3] = neighbours[3] > MAP_LENGTH * MAP_WIDTH ? -1 : neighbours[3];

		// remove from queue
		queue.pop_front();

		// for each neighbouring tile
		for (int k = 0; k < 4; k++) {
			cout << neighbours[k] << endl;
			//if can be reached, not already visited, and not wall
			if (neighbours[k] != -1 && !visited[neighbours[k]] && (map[(int)(neighbours[k] / MAP_WIDTH)][neighbours[k] % MAP_WIDTH]).wallOrOtherChar != Map::WALL) {
				//if exit found, break out of for and leave while loop
				if ((map[(int)(neighbours[k] / MAP_WIDTH)][neighbours[k] % MAP_WIDTH]).wallOrOtherChar == Map::END) {
					delete[] visited;
					return true;
				}
				//else, mark as visited and set to explore later
				visited[neighbours[k]] = true;
				queue.push_back(neighbours[k]);
			}
		}
	}

	//deallocate memory
	delete[] visited;

	//return value
	return false;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @param obj: a character value of object that fills the cell
void Map::fillCell(int x, int y, MapObject obj)
{
	//map[x][y] = obj;
	if (obj.getDisplayChar() == 'P') {
		PlayerPositionX = x;
		PlayerPositionY = y;
	}
	MapObject* omo = new MapObject;
	omo = &map[x][y];
	*omo = obj;

	//char* oc = new char;
	//oc = &map[x][y];
	//*oc = obj;
	Notify();
}

//! Implementation of get cell, returns cell at given location
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
char Map::getCell(int x, int y)
{
	return map[x][y].getDisplayChar();
}

int Map::getHeight()
{
	return MAP_LENGTH;
}

int Map::getWidth()
{
	return MAP_WIDTH;
}

//! Implementation of selecting entrance, set any cell to the map's entrance
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
void Map::setEntrance(int x, int y) {
	MapObject begin = MapObject(x, y);
	begin.setWallOrOtherChar('B');
	fillCell(x, y, begin);
}

//! Implementation of selecting exit, set any cell to the map's exit
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
void Map::setExit(int x, int y) {
	MapObject end = MapObject(x, y);
	end.setWallOrOtherChar('E');
	fillCell(x, y, end);
}

//! Implementation occupation of a cell, check if a cell is occupied
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
//! @return : a boolean true if the cell is occupeid false otherwise
bool Map::isOccupied(int x, int y)
{
	if ((map[x][y]).wallOrOtherChar != ' ') {
		return true;
	}
	return false;
}

//int main() {
//	Map* map = new Map();
//
//	map->setEntrance(0, 0);
//	map->setExit(1, 1);
//
//	bool valid = map->validatePath();
//
//	if (valid) cout << "Path is valid!" << endl;
//	else cout << "Path is invalid!" << endl;
//
//	delete map;
//
//	return 0;
//}