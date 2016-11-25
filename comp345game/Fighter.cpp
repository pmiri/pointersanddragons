#include "Character.h"

class Fighter : public Character
{
public:
	//! The default Character constructor is called, followed bythe Fighter constructor to set up character stats
	Fighter()
	{
		className = "Fighter";
	}

	Fighter(int str, int dex, int con, int intel, int wis, int cha, char isP)
	{
		className = "Fighter";
	}

	Fighter(int str, int dex, int con, int intel, int wis, int cha, char isP, int level)
	{
		className = "Fighter";
	}
};