//! @file 
//! @brief Declaration file for the ItemUI class  
//!
#pragma once
#include "Inventory.h"
#include "Backpack.h"
#include "Observer.h"

class ItemUI
{
public:
	ItemUI(Inventory* i, Backpack* b);
	void PrintInventory();
	std::string getInventoryString();
	std::string getBackpackString();
private:
	Inventory *inv;
	Backpack *back;
	std::string invString;
	std::string backString;
};