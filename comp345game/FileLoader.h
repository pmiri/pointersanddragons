//! @file 

#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include "dirent.h"
#include <list>
#include "Map.h"
#include "Campaign.h"
#include "MapBuilder.h"
using namespace std;

class FileLoader
{
public:
	static string mapSelection();
	static string characterSelection();
private:
	static inline char keyPress() {
		int i = _getche();
		char input = static_cast<char>(i);
		cout << endl;
		return input;
	};
};
