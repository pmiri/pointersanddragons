//! @file 
//! @brief Header file for the Enhancement class  
//! Enhancements grant bonuses to an item
//! Note that enhancements are always positive, unlike D20 rules
//! Enhancements can range from +0 to +5, in accordance with the SRD
//! Enhancements cna affect Armor class, Damage, or any of the Attributes, 
//! as in the SRD, but only certain bonuses are available on certain items
#ifndef Enhancement_h
#define Enhancement_h

#include <string>
#include<vector>
using namespace std;

//! class for the implementation of an enhancement, i.e. a stat influenced by an item, as well as the bonus it gives
class Enhancement
{
public:
	// Default constructor
	Enhancement();
	// Constructor
	Enhancement(string type, int bonus);
	// method to get the type of the bonus
	string getType();
	// method to get the bonus of the type
	int getBonus();
	void setBonus(int setBonus);
private:
	string type;
	int bonus;
};

#endif

