//! @file 
//! @brief Implementation file for the Map class  
//!
#include "Map.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

inline char mapKeyPress() {
	int i = _getche();
	char input = static_cast<char>(i);
	cout << endl;
	return input;
}

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
	bool targetOutOfBounds = false;

	switch (toupper(dir)) {
	case 'W':
		if (PlayerPositionY - 1 >= 0)//valid up move
		{
			newYPosition = PlayerPositionY - 1;
		}
		else
			targetOutOfBounds = true;
		break;
	case 'A':
		if (PlayerPositionX - 1 >= 0)//valid left move
		{
			newXPosition = PlayerPositionX - 1;
		}
		else
			targetOutOfBounds = true;
		break;
	case 'S':
		if (PlayerPositionY + 1 < MAP_LENGTH)//valid down move
		{
			newYPosition = PlayerPositionY + 1;
		}
		else
			targetOutOfBounds = true;
		break;
	case 'D':
		if (PlayerPositionX + 1 < MAP_WIDTH)//valid right move
		{
			newXPosition = PlayerPositionX + 1;
		}
		else
			targetOutOfBounds = true;
		break;
	default:
		Notify();
		cout << "no move" << endl;
		return;//OTHERWISE THE PLAYER GETS SET TO NULL ON AN INVLID KEY
	}
	targetCellContent = getCell(newXPosition, newYPosition);
	if (targetCellContent == 'W' || targetOutOfBounds) {
		Notify();
		cout << endl << "That move is invalid!" << endl;//the move is invalid
		return;
	}
	if (targetCellContent == 'M') {
		Notify();
		cout << endl << "Would you like to fight this monster? (Y)" << endl;
		char in = mapKeyPress();
		if (toupper(in) == 'Y') {
			cout << "Begin Fight sequence" << endl;
		}
		else
			cout << "You have not fought" << endl;
		return;
	}

	//put player character at mapObject of target
	map[newXPosition][newYPosition].setCharacter(map[PlayerPositionX][PlayerPositionY].getCharacter());
	//remove player character pointer from previous location
	map[PlayerPositionX][PlayerPositionY].setCharacter(nullptr);
	//update player location variables
	PlayerPositionX = newXPosition;
	PlayerPositionY = newYPosition;
	Notify();
	if (targetCellContent == 'E') {
		Notify();
		cout << endl << "You are at the Exit, would you like to go to the next map? (Y)" << endl;
		char in = mapKeyPress();
		if (toupper(in) == 'Y') {
			cout << "Place player at B of next map in Campaign" << endl;
		}
		else
			cout << "You have not proceeded" << endl;
		return;
	}
	if (targetCellContent == 'B') {
		Notify();
		cout << endl << "You are at the Beginning, would you like to go to the previous map? (Y)" << endl;
		char in = mapKeyPress();
		if (toupper(in) == 'Y') {
			cout << "Place player at E of previous map in Campaign" << endl;
		}
		else
			cout << "You have not gone back" << endl;
		return;
	}
	if (targetCellContent == 'T') {
		Notify();
		bool openingChest;
		cout << endl << "A Treasure chest, would you like to open it? (Y)" << endl;
		char in = mapKeyPress();
		if (toupper(in) == 'Y') {
			cout << "You open the chest." << endl;
			openingChest = true;
		}
		else
		{
			openingChest = false;
			cout << "You have not opened it" << endl;
		}
		while (openingChest)
		{
			system("cls");
			map[PlayerPositionX][PlayerPositionY].getCharacter()->itemManager.printChestInventory(map[PlayerPositionX][PlayerPositionY].getItems());
			cout << "Use 0-9 to grab items from the chest, c to close it." << endl;
			in = mapKeyPress();
			if (in == 'c')
			{
				Notify();
				cout << "You close the chest" << endl;
				openingChest = false;
			}
			else
			{
				map[PlayerPositionX][PlayerPositionY].getCharacter()->itemManager.grabFromChest(map[PlayerPositionX][PlayerPositionY].getItems(), in);
			}			
		}
		return;
	}
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
	if (obj.getDisplayChar() == 'B') {
		BeginPositionX = x;
		BeginPositionY = y;
	}
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
	//Notify();
}

void Map::PlacePlayer() {
}

//! Implementation of get cell, returns cell at given location
//! @param x: an integer value of horizontal index of the map's grid
//! @param y: an integer value of vertical index of the map's grid
char Map::getCell(int x, int y)
{
	return map[x][y].getDisplayChar();
}

MapObject Map::getMapObjectAt(int x, int y)
{
	return map[x][y];
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