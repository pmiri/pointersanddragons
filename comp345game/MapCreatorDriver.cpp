#include "MapCreator.h"
#include <iostream>

int main()
{
	std::cout << "Building 4x4 map..." << std::endl;
	char charArray[] = {'W', 'W', 'W', 'W',
						'W', 'B', ' ', 'W',
						'W', ' ', 'E', 'W',
						'W', 'W', 'W', 'W'};
	Map baseMap = Map(4, 4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 | i == 3 | j == 0 | j == 3)
				baseMap.fillCell(i, j, 'W');
			else if (i == 1)
			{
				if (j == 1)
				{
					baseMap.fillCell(i, j, 'B');
				}
				else
				{
					baseMap.fillCell(i, j, ' ');
				}
			}
			else
			{
				if (j == 1)
				{
					baseMap.fillCell(i, j, ' ');
				}
				else
				{
					baseMap.fillCell(i, j, 'E');
				}
			}
		}
	}
	Map testMap = *MapCreator::buildMap(charArray, 4, 4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << testMap.getCell(i, j);
		}
		std::cout << std::endl;
	}
	bool goodCopy = true;
	for (int i = 0; i < 4; i++)
	{
		if (!goodCopy)
			break;
		for (int j = 0; j < 4; j++)
		{
			if (baseMap.getCell(i, j) != testMap.getCell(i, j))
			{
				goodCopy = false;
				break;
			}
		}
	}
	if (goodCopy)
	{
		std::cout << "Success!" << std::endl;
		std::cout << "Saving map to file..." << std::endl;
		MapCreator::saveMap(testMap, "test.txt");
		std::cout << "Loading map from file..." << std::endl;
		Map fileTestMap = *MapCreator::loadMap("test.txt");
		goodCopy = true;
		for (int i = 0; i < 4; i++)
		{
			if (!goodCopy)
				break;
			for (int j = 0; j < 4; j++)
			{
				if (baseMap.getCell(i, j) != fileTestMap.getCell(i, j))
				{
					goodCopy = false;
					break;
				}
			}
		}		
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << fileTestMap.getCell(i, j);
			}
			std::cout << std::endl;
		}
		if (goodCopy)
		{
			std::cout << "Success!" << std::endl;
			std::cout << "Building Campaign..." << std::endl;
			std::vector<Map> mapVector;
			mapVector.push_back(baseMap);
			Map maps[] = {baseMap};
			Campaign baseCampaign = Campaign(mapVector, "Base Campaign");
			Campaign testCampaign = *MapCreator::buildCampaign(maps, 1, "Test Campaign");
			if (baseCampaign.getSize() == testCampaign.getSize())
			{
				Map baseCampaignMap = baseCampaign.getMapAt(0);
				Map testCampaignMap = testCampaign.getMapAt(0);
				goodCopy = true;
				for (int i = 0; i < 4; i++)
				{
					if (!goodCopy)
						break;
					for (int j = 0; j < 4; j++)
					{
						if (baseCampaignMap.getCell(i, j) != testCampaignMap.getCell(i, j))
						{
							goodCopy = false;
							break;
						}
					}
				}
				if (goodCopy)
				{
					std::cout << "Success!" << std::endl;					
					std::string filepaths[] = {"testCampaign.txt", "test1.txt"};
					std::cout << "Saving Campaign to file..." << std::endl;
					MapCreator::saveCampaign(testCampaign, filepaths);
					std::cout << "Loading Campaign from file..." << std::endl;
					Campaign fileTestCampaign = *MapCreator::loadCampaign(filepaths[0]);
					if (fileTestCampaign.getSize() == baseCampaign.getSize())
					{
						Map fileTestCampaignMap = fileTestCampaign.getMapAt(0);
						goodCopy = true;
						for (int i = 0; i < 4; i++)
						{
							if (!goodCopy)
								break;
							for (int j = 0; j < 4; j++)
							{
								if (baseCampaignMap.getCell(i, j) != fileTestCampaignMap.getCell(i, j))
								{
									goodCopy = false;
									break;
								}
							}
						}
						if (goodCopy)
						{
							std::cout << "Success!" << std::endl;
							std::cout << "All functions succeeded!" << std::endl;
						}
						else
							std::cout << "Failure..." << std::endl;
					}
					else
						std::cout << "Failure..." << std::endl;
				}
				else
					std::cout << "Failure..." << std::endl;
			}
			else
				std::cout << "Failure..." << std::endl;
		}
		else
			std::cout << "Failure..." << std::endl;
	}
	else
		std::cout << "Failure..." << std::endl;
	std::string userInput = "";
	std::cin >> userInput;
}