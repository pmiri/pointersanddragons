#include "FileLoader.h"

string FileLoader::mapSelection()
{
	const string MAPS_PATH = "../maps/";
	Campaign *campaign;
	list<string> maps;
	DIR *dir;
	struct dirent *ent;
	campaign = new Campaign(3);
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
			string name = ent->d_name;
			if (name.find("campaign") != std::string::npos) {
				campaign->addMap(*MapBuilder::buildFromFile(MAPS_PATH + ent->d_name));
			}
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
