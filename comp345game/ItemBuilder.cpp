#include "ItemBuilder.h"

Item ItemBuilder::buildItem()
{
	std::cout << "Welcome to the Item Creator!\n";
	string itemName;
	std::cout << "Please state the item name\n";
	std::cin >> itemName;
	string itemType;
	bool invalidInput = false;
	do
	{
		std::cout << "Please state the type\n";
		std::cin >> itemType;
		invalidInput = !Item::validateType(itemType);
		if (invalidInput)
		{
			std:: cout << itemType << " is not a valid item type.\n";
		}
	} while (invalidInput);	
	std::vector<Enhancement> itemEnhancements;
	int numOfEnhance = 0;
	bool addingMore = true;
	std::cout << "Item name is " << itemName << " and the type is " << itemType;
	while (addingMore)
	{
		string enhanceType;
		do
		{
			std::cout << "Please state the enhancement type\n";
			std::cin >> enhanceType;
			if (Item::validateEnhancementType(itemType, enhanceType))
			{
				std::cout << enhanceType << " is not a valid enhancement type.\n";
			}
		} while (invalidInput);
	}
	return Item();
}

Item ItemBuilder::loadItem(std::string filepath)
{
	return Item();
}

void ItemBuilder::saveItem(std::string filepath, Item i)
{
}
