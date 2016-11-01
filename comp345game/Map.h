//! @file 
//! @brief Implementation file for the Map class  
//!
#pragma once

//! Class implementing a game map
class Map
{
public:
	//! constants for cell objects
	static char const WALL = 'W';
	static char const BEGIN = 'B';
	static char const END = 'E';

	bool validatePath();
	void fillCell(int x, int y, char obj);
	bool isOccupied(int x, int y);
	void setEntrance(int x, int y);
	void setExit(int x, int y);
	char getCell(int x, int y);

	Map();
	Map(int width, int height);
};

