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
		if (userInput == "(m)" || userInput == "m")
		{
			int length;
			int width;
			std::cout << "How tall should the map be?" << std::endl;
			std::cout << "How wide should the map be?" << std::endl;
		}
		else if (userInput == "(c)" || userInput == "c")
		{

		}
		else if (userInput == "(q)" || userInput == "q")
		{
			std::cout << "Goodbye!" << std::endl;
			running = false;
		}
		else
			std::cout << "I didn't understand that, sorry!" << std::endl;
	}
}