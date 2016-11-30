//! @file 
//! @brief Declaration file for the Item builder class  
//!
#pragma once
#include "Item.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "dirent.h"

class ItemBuilder
{
public:
	static Item buildItem();
	static Item loadItem(std::string filepath);
	static void saveItem(std::string filepath, Item i);
	static Item editItem(Item i);
private:
	static inline char keyPress() {
		int i = _getche();
		char input = static_cast<char>(i);
		cout << endl;
		return tolower(input);
	}
	static Item setItemName(Item i);
	static Item setItemType(Item i);
	static Item setItemEnhancement(Item i);
	static Item removeEnhancement(Item i);
	static Item editEnhancement(Item i);
	static Item addEnhancement(Item i);
	static bool quit(Item i);
};