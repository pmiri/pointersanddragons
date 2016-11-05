#include "stdafx.h"
#include "CppUnitTest.h"
#include "MapCreator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapEditorTester
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBuildMap)
		{
			char charArray[] = { 'W', 'W', 'W', 'W',
								'W', 'B', ' ', 'W',
								'W', ' ', 'E', 'W',
								'W', 'W', 'W', 'W' };
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
			Assert::AreEqual(goodCopy, true);
		}

		TEST_METHOD(TestSaveLoadMap)
		{
			char charArray[] = { 'W', 'W', 'W', 'W',
								'W', 'B', ' ', 'W',
								'W', ' ', 'E', 'W',
								'W', 'W', 'W', 'W' };
			Map testMap = *MapCreator::buildMap(charArray, 4, 4);
			MapCreator::saveMap(testMap, "test.txt");
			Map fileTestMap = *MapCreator::loadMap("test.txt");
			bool goodCopy = true;
			for (int i = 0; i < 4; i++)
			{
				if (!goodCopy)
					break;
				for (int j = 0; j < 4; j++)
				{
					if (testMap.getCell(i, j) != fileTestMap.getCell(i, j))
					{
						goodCopy = false;
						break;
					}
				}
			}
			Assert::AreEqual(goodCopy, true);
		}

		TEST_METHOD(TestBuildCampaign)
		{
			char charArray[] = { 'W', 'W', 'W', 'W',
								'W', 'B', ' ', 'W',
								'W', ' ', 'E', 'W',
								'W', 'W', 'W', 'W' };
			std::vector<Map> mapVector;
			bool goodCopy = true;
			Map baseMap = *MapCreator::buildMap(charArray, 4, 4);
			mapVector.push_back(baseMap);
			Map maps[] = { baseMap };
			Campaign baseCampaign = Campaign(mapVector, "Base Campaign");
			Campaign testCampaign = *MapCreator::buildCampaign(maps, 1, "Test Campaign");
			if (baseCampaign.getSize() == testCampaign.getSize())
			{
				Map baseCampaignMap = baseCampaign.getMapAt(0);
				Map testCampaignMap = testCampaign.getMapAt(0);
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
			}
			else
				goodCopy = false;
			Assert::AreEqual(goodCopy, true);
		}

		TEST_METHOD(TestSaveLoadCampaign)
		{
			char charArray[] = { 'W', 'W', 'W', 'W',
								'W', 'B', ' ', 'W',
								'W', ' ', 'E', 'W',
								'W', 'W', 'W', 'W' };
			std::vector<Map> mapVector;
			bool goodCopy = true;
			Map baseMap = *MapCreator::buildMap(charArray, 4, 4);
			mapVector.push_back(baseMap);
			Map maps[] = { baseMap };
			Campaign baseCampaign = Campaign(mapVector, "Base Campaign");
			std::string filepaths[] = { "baseCampaign.txt", "test1.txt" };
			MapCreator::saveCampaign(baseCampaign, filepaths);
			Campaign fileTestCampaign = *MapCreator::loadCampaign(filepaths[0]);
			if (fileTestCampaign.getSize() == baseCampaign.getSize())
			{
				Map fileTestCampaignMap = fileTestCampaign.getMapAt(0);
				Map baseCampaignMap = baseCampaign.getMapAt(0);
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
			}
			Assert::AreEqual(goodCopy, true);
		}

	};
}