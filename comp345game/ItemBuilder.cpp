#include "ItemBuilder.h"

Item ItemBuilder::buildItem()
{
	std::cout << "Welcome to the Item Creator!\n";
	string input;
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
			invalidInput = !Item::validateEnhancementType(itemType, enhanceType);
			if (invalidInput)
			{
				std::cout << enhanceType << " is not a valid enhancement type for" << itemType << ".\n";
			}
		} while (invalidInput);
		invalidInput = false;
		int enhanceBonus = 0;
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
		Enhancement tempEnhance = Enhancement(enhanceType, enhanceBonus);
		itemEnhancements.push_back(tempEnhance);
		std::cout << "Would you like to stop adding enhancements?\n";
		std::cin >> input;
		if (input == "yes" || input == "Yes" || input == "y" || input == "Y")
			addingMore = false;
	}
	Item customItem = Item(itemType, itemEnhancements, itemName);
	return customItem;
}

Item ItemBuilder::loadItem(std::string filepath)
{
	std::string currentLine = "";
	std::ifstream fileToLoad;
	fileToLoad.open(filepath);
	if (fileToLoad.is_open())
	{
		string itemName;
		string itemType;
		int numberOfEnhancements;
		if (getline(fileToLoad, currentLine))
			itemName = currentLine;
		else
			return Item();
		if (getline(fileToLoad, currentLine))
			itemType = currentLine;
		else
			return Item();
		if (getline(fileToLoad, currentLine))
			numberOfEnhancements = atoi(currentLine.c_str());
		else
			return Item();
		std::vector<Enhancement> itemEnhancements;
		for (int i = 0; i < numberOfEnhancements; i++)
		{
			string enhanceType;
			int enhanceBonus;
			if (getline(fileToLoad, currentLine))
				enhanceType = currentLine;
			else
				return Item();
			if (getline(fileToLoad, currentLine))
				enhanceBonus = atoi(currentLine.c_str());
			else
				return Item();
			Enhancement tempEnhance = Enhancement(enhanceType, enhanceBonus);
			itemEnhancements.push_back(tempEnhance);
		}
		fileToLoad.close();
		Item loadedItem = Item(itemType, itemEnhancements, itemName);
	}
	else
		std::cout << "Error in opening file \n";
	return Item();
}

void ItemBuilder::saveItem(std::string filepath, Item i)
{
	if (i.validateItem())
	{
		std::ofstream fileToWrite;
		fileToWrite.open(filepath, std::ifstream::out | std::ifstream::trunc);
		fileToWrite.clear();
		if (fileToWrite.is_open())
		{
			fileToWrite << i.getName() << std::endl;
			fileToWrite << i.getType() << std::endl;
			std::vector<Enhancement> itemEnhancements = i.getInfluences();
			int numOfEnhance = itemEnhancements.size();
			fileToWrite << numOfEnhance << std::endl;
			for (int i = numOfEnhance; i > 0; i--)
			{
				Enhancement temp = itemEnhancements.at(i);
				fileToWrite << temp.getType() << std::endl;
				fileToWrite << temp.getBonus() << std::endl;
			}
			fileToWrite.close();
			std::cout << "Item Saved!\n";
		}
		else
			std::cout << "Error in opening file.\n";
	}
	else
	{
		std::cout << "Error: Item is invalid.\n";
	}
}
