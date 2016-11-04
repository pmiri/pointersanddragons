#include "MapCreator.h"
#include <iostream>

int main()
{
	std::cout << "Building 4x4 map" << std::endl;
	char charArray[] = {'W', 'W', 'W', 'W',
						'W', 'B', ' ', 'W',
						'W', ' ', 'E', 'W',
						'W', 'W', 'W', 'W'};
	Map testMap = *MapCreator::buildMap(charArray, 4, 4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << testMap.getCell(i, j);
		}
		std::cout << std::endl;
	}
	if(testMap.validatePath())
		std::cout << "Success!" << std::endl;
	else
		std::cout << "Failure..." << std::endl;
	std::string userInput = "";
	std::cin >> userInput;
}