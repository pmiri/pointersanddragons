//! @file 
//! @brief Declaration file for the ItemUI class  
//!
#pragma once
#include "Inventory.h"
#include "Backpack.h"

class ItemUI
{
public:
	ItemUI(Inventory* i, Backpack* b);
	void PrintInventory();
	std::string getInventoryString();
	std::string getBackpackString();
	void equipFromBackpack(char dir);
private:
	Inventory *inv;
	Backpack *back;
	std::string invString;
	std::string backString;
};