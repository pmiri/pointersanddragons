//! @file 
//! @brief Declaration file for the Item builder class  
//!
#pragma once
#include "Item.h"
#include <iostream>
#include <fstream>

class ItemBuilder
{
public:
	Item buildItem();
	Item loadItem(std::string filepath);
	void saveItem(std::string filepath, Item i);
};