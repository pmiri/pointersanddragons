//! @file 
//! @brief Implementation file for the Campaign class  
//!
#include "Campaign.h"
#include <iostream>

using namespace std;

Campaign::Campaign()
{
	mapCount = 0;
}

Campaign::Campaign(int campaignSize)
{
	mapList = new Map[campaignSize];
	mapCount = 0;
}

void Campaign::addMap(Map m)
{
	mapList[mapCount] = m;
	mapCount++;
}