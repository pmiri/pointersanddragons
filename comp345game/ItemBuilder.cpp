#include "ItemBuilder.h"

Item ItemBuilder::buildItem()
{
	std::cout << "Welcome to the Item Creator!\n";
	string input;
	string itemName;
	std::cout << "Please state the item name\n";
	std::getline(std::cin, itemName);
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
	std::cout << "Item name is " << itemName << " and the type is " << itemType << endl;
	while (addingMore)
	{
		string enhanceType;
		do
		{
			std::cout << "Please state the enhancement type\n";
			std::getline(std::cin, enhanceType);
			invalidInput = !Item::validateEnhancementType(itemType, enhanceType);
			if (invalidInput)
			{
				std::cout << enhanceType << " is not a valid enhancement type for " << itemType << ".\n";
			}
		} while (invalidInput);
		invalidInput = false;
		int enhanceBonus = 0;
		do
		{
			std::cout << "Please state the enhancement bonus\n";
			std::cin >> enhanceBonus;
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
	Item loadedItem;
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
		loadedItem = Item(itemType, itemEnhancements, itemName);
	}
	else
		std::cout << "Error in opening file \n";
	return loadedItem;
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
			for (int i = (numOfEnhance -1); i >= 0; i--)
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

Item ItemBuilder::editItem(Item i)
{
	std::cout << "Welcome to the Item Editor!\n";
	string input;
	bool editing = true;
	while (editing)
	{
		std::cout << "Here is your item:" << endl;
		std::cout << "Item name: " << i.getName() << endl;
		std::cout << "Item type: " << i.getType() << endl;
		std::vector<Enhancement> itemEnhancements = i.getInfluences();
		int numEnhance = itemEnhancements.size();
		for (int i = 0; i < numEnhance; i++)
		{
			std::cout << "Enhancement #" << i << ": " << itemEnhancements.at(i).getType() << " +" << itemEnhancements.at(i).getBonus() << endl;
		}
		std::cout << "What would you like to edit?\n";
		std::cout << "Press n to edit name, t to edit type, e to edit enhancements, and q to quit.\n";
		std::cin >> input;
		if (input == "n" || input == "N")
		{
			std::cout << "Please state the item name\n";
			std::getline(std::cin, input);
			i.setName(input);
		}
		else if (input == "t" || input == "T")
		{
			string itemType;
			bool invalidInput = false;
			do
			{
				std::cout << "Please state the type\n";
				std::cin >> itemType;
				invalidInput = !Item::validateType(itemType);
				if (invalidInput)
				{
					std::cout << itemType << " is not a valid item type.\n";
				}
			} while (invalidInput);
		}
		else if (input == "e" || input == "E")
		{
			std::cout << "What would you like to edit?\n";
			std::cout << "Press r to remove an enhancement, e to edit one, or a to add a new one.\n";
			std::cin >> input;
			if (input == "r" || input == "R")
			{
				bool invalidInput = false;
				do
				{
					std::cout << "Please enter the index of the enhancement to remove.\n";
					std::cin >> input;
					int index = atoi(input.c_str());
					if (index < 0 || index > itemEnhancements.size())
					{
						std::cout << "No enhancement at that index.\n";
						invalidInput = true;
					}
					else
					{
						itemEnhancements.erase(itemEnhancements.begin() + index);
					}
				} while (invalidInput);				
			}
			else if (input == "e" || input == "E")
			{
				bool invalidInput = false;
				do
				{
					std::cout << "Please enter the index of the enhancement to edit.\n";
					std::cin >> input;
					int index = atoi(input.c_str());
					if (index < 0 || index > itemEnhancements.size())
					{
						std::cout << "No enhancement at that index.\n";
						invalidInput = true;
					}
					else
					{
						string enhanceType;
						do
						{
							std::cout << "Please state the enhancement type\n";
							std::getline(std::cin, enhanceType);
							invalidInput = !Item::validateEnhancementType(i.getType(), enhanceType);
							if (invalidInput)
							{
								std::cout << enhanceType << " is not a valid enhancement type for" << i.getType() << ".\n";
							}
						} while (invalidInput);
						invalidInput = false;
						int enhanceBonus = 0;
						do
						{
							std::cout << "Please state the enhancement bonus\n";
							std::cin >> enhanceBonus;
							enhanceBonus = atoi(enhanceType.c_str());
							if (enhanceBonus < 0 || enhanceBonus > 5)
							{
								std::cout << enhanceBonus << " is not between 0 and 5.\n";
							}
						} while (invalidInput);
						Enhancement tempEnhance = Enhancement(enhanceType, enhanceBonus);
						itemEnhancements.erase(itemEnhancements.begin()+ index);
						itemEnhancements.insert(itemEnhancements.begin()+ index, tempEnhance);
					}
				} while (invalidInput);
			}
			else if (input == "a" || input == "A")
			{
				bool invalidInput = false;
				string enhanceType;
				do
				{
					std::cout << "Please state the enhancement type\n";
					std::getline(std::cin, enhanceType);
					invalidInput = !Item::validateEnhancementType(i.getType(), enhanceType);
					if (invalidInput)
					{
						std::cout << enhanceType << " is not a valid enhancement type for" << i.getType() << ".\n";
					}
				} while (invalidInput);
				invalidInput = false;
				int enhanceBonus = 0;
				do
				{
					std::cout << "Please state the enhancement bonus\n";
					std::cin >> enhanceBonus;
					enhanceBonus = atoi(enhanceType.c_str());
					if (enhanceBonus < 0 || enhanceBonus > 5)
					{
						std::cout << enhanceBonus << " is not between 0 and 5.\n";
					}
				} while (invalidInput);
				Enhancement tempEnhance = Enhancement(enhanceType, enhanceBonus);
				itemEnhancements.push_back(tempEnhance);
			}
		}
		else if (input == "q" || input == "Q")
		{
			if (!i.validateItem())
			{
				std::cout << "The item currently is invalid and cannot be saved until further editing is done.\n";
				std::cout << "Press q to quit anyways.\n";
				std::cin >> input;
				if (input == "q" || input == "Q")
					return i;
			}
			else
			{
				return i;
			}			
		}
	}	
	return i;
}
