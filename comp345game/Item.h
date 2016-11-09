//! @file 
//! @brief Header file for the Item class  
//! Items are based on D&D 3.5, though rather simplified.
//! Items have a type and set of enhancements that influence them, and can be valid or invalid.
//! Type is represented by a string, only certain types are allowable
//! Influences are enhancements, which have individual types and bonuses, as seen in enhancement
//! More detail in implementation.
#ifndef Item_h
#define Item_h

#include <string>
#include <vector>
#include "Enhancement.h"
using namespace std;

//! class for the implementation of items wearable by a character
class Item
{
public:
	// Default constructor
	Item();
	// Constructor
	Item(string type, vector<Enhancement> influences);
	Item(string type, vector<Enhancement> influences, string name);
	// method to get the type of the item
	string getType();
	// method to get the influences of the item
	vector<Enhancement> getInfluences();
	//method to validate an item
	bool validateItem();
	string getName();
	void setName(string newName);
private:
	string name;
	string type;
	bool valid;
	vector<Enhancement> influence;
};
#endif

