//! @file 
//! @brief Implementation file for the Campaign class  
//! The Campaign class contains th order inwhich mapsare traversed
//!
#pragma once

using namespace std;
#include "Map.h"
#include <string>
#include <vector>
class Campaign
{
public:
	Campaign();
	Campaign(int);
	string name;
	void addMap(string);
	void addMap(string, int);
	Map* buildMapFrom(int);
	string getMapAt(int);
	string nextMap();
	string previousMap();
	void removeMap(int);
	void editMap(Map*, int);
	int getSize();

	Campaign(string);
	Campaign(vector<string>, string);
private:
	vector<string> mapsInCampaign;
	int currentMapIndex = 0;
};
