#include "Character.h"

class Fighter : public Character
{
public:
	//! The default Character constructor is called, followed bythe Fighter constructor to set up character stats
	Fighter()
	{
		className = "Fighter";
		//fighter max hit points is initially 10
		maxHitPoints = 10;
		armorClass = 10;
		initAbilityModifiers();
	}

	Fighter(int str, int dex, int con, int intel, int wis, int cha, char isP)
	{
		className = "Fighter";
		isPlayer = isP;
		//fighter max hit points is initially 10, then affected by ability modifiers
		maxHitPoints = 10;
		initAbilityModifiers();
	}

	int levelUp(int diceRoll)
	{
		level++;
		maxHitPoints = maxHitPoints + diceRoll;
		int skillPoints = 2 + abilityScores[3];
		distributePoints(skillPoints);
	}
};