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
	static Item buildItem();
	static Item loadItem(std::string filepath);
	static void saveItem(std::string filepath, Item i);
};