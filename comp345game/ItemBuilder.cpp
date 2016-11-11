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
	string enhanceType;
	int enhanceBonus = 0;
	while (addingMore)
	{
		do
		{
			std::cout << "Please state the enhancement type\n";
			std::cin >> enhanceType;
			invalidInput = !Item::validateEnhancementType(itemType, enhanceType);
			if (invalidInput)
			{
				std::cout << enhanceType << " is not a valid enhancement type for" << itemType << ".\n";
			}
		} while (invalidInput);
		invalidInput = false;
		do
		{
			std::cout << "Please state the enhancement bonus\n";
			std::cin >> enhanceType;
			enhanceBonus = atoi(enhanceType.c_str());
			if (enhanceBonus < 0 || enhanceBonus > 5)
			{
				std::cout << enhanceBonus << " is not between 0 and 5.\n";
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
