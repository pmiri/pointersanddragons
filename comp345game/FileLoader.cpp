#include "FileLoader.h"

string FileLoader::mapSelection()
{
	const string MAPS_PATH = "../maps/";
	list<string> maps;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(MAPS_PATH.c_str())) != NULL) {
		/* print all the files and directories within directory */
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i < 0) {
				i++;
				continue;
			}
			printf("[%d] %s\n", i, ent->d_name);
			maps.push_back(ent->d_name);
			i++;
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("Could not find map directory.");
		return "" + EXIT_FAILURE;
	}

	char c = keyPress();
	int index = c - 48;

	for (int i = 0; i < index; i++) {
		maps.pop_front();
	}
	return maps.front();
}

string FileLoader::campaignSelection()
{
	const string MAPS_PATH = "../maps/";
	list<string> campaigns;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(MAPS_PATH.c_str())) != NULL) {
		/* print all the files and directories within directory */
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i < 0) {
				i++;
				continue;
			}
			if (isCampaign(ent->d_name));
			{
				printf("[%d] %s\n", i, ent->d_name);
				campaigns.push_back(ent->d_name);
				i++;
			}			
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("Could not find map directory.");
		return "" + EXIT_FAILURE;
	}

	char c = keyPress();
	int index = c - 48;

	for (int i = 0; i < index; i++) {
		campaigns.pop_front();
	}
	return campaigns.front();
}

bool FileLoader::isCampaign(string filepath)
{
	std::string currentLine = "";
	std::ifstream fileToLoad;
	fileToLoad.open(filepath);
	if (fileToLoad.is_open())
	{
		if (!getline(fileToLoad, currentLine))
		{
			return false;
			std::cout << "Error in reading file \n";
		}
		else
		{
			if (currentLine == "")
			{
				if (!getline(fileToLoad, currentLine))
				{
					return false;
					std::cout << "Error in reading file \n";
				}
				else
				{
					if (currentLine != "")
					{
						return true;
					}
					else
						return false;
				}
			}
			else
				return false;
		}
	}
	else
	{
		return false;
		std::cout << "Error in opening file \n";
	}
}

string FileLoader::characterSelection()
{
	const string CHARACTERS_PATH = "../characters/";
	list<string> characters;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(CHARACTERS_PATH.c_str())) != NULL) {
		/* print all the files and directories within directory */
		int i = -2;
		while ((ent = readdir(dir)) != NULL) {
			if (i < 0) {
				i++;
				continue;
			}
			printf("[%d] %s\n", i, ent->d_name);
			characters.push_back(ent->d_name);
			i++;
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("Could not find characters directory.");
		return "" + EXIT_FAILURE;
	}

	char c = keyPress();
	int index = c - 48;

	for (int i = 0; i < index; i++) {
		characters.pop_front();
	}
	return characters.front();
}
