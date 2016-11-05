#include "MapCreator.h"
#include <iostream>

int main()
{
	std::string userInput = "";
	bool running = true;
	while (running)
	{
		std::cout << "Welcome to the Map Editor!" << std::endl << "Would you like to make a map (m), a campaign (c), or quit (q)?" << std::endl;
		std::cin >> userInput;
		if (userInput == "(m)" || userInput == "m" || userInput == "M" || userInput == "(M)")
		{
			int length;
			int width;
			length = MapCreator::getLength();
			width = MapCreator::getWidth();
			Map customMap = *MapCreator::buildMap(length, width);
			std::cout << "Here is the finished map!" << std::endl;
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					std::cout << customMap.getCell(i, j) << std::endl;
				}
			}
			std::cout << "Would you like to save the map (y) or not (n)?" << std::endl;
			std::cin >> userInput;
			if (userInput == "(y)" || userInput == "y" || userInput == "Y" || userInput == "(Y)")
			{
				MapCreator::saveMap(customMap);
				std::cout << "Map saved. Returning to menu!" << std::endl;
			}
			else
			{
				std::cout << "Map discarded. Returning to menu!" << std::endl;
			}
		}
		else if (userInput == "(c)" || userInput == "c" || userInput == "C" || userInput == "(C)")
		{

		}
		else if (userInput == "(q)" || userInput == "q" || userInput == "Q" || userInput == "(Q)")
		{
			std::cout << "Goodbye!" << std::endl;
			running = false;
		}
		else
			std::cout << "I didn't understand that, sorry!" << std::endl;
	}
}