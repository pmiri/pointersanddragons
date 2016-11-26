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

		isPlayer = isP;
		abilityScores[0] = str;
		abilityScores[1] = dex;
		abilityScores[2] = con;
		abilityScores[3] = intel;
		abilityScores[4] = wis;
		abilityScores[5] = cha;
		for (int i = 0; i < 6; i++)
		{
			abilityBonuses[i] = 0;
		}
		//default hit points is 10 but is affected by ability modifiers.
		maxHitPoints = 10;
		initAbilityModifiers();
		currentHitPoints = maxHitPoints;
		baseAttackBonus = 1;
		level = 1;

	}

	Fighter(int str, int dex, int con, int intel, int wis, int cha, char isP, int lvl)
	{
		className = "Fighter";

		isPlayer = isP;
		abilityScores[0] = str;
		abilityScores[1] = dex;
		abilityScores[2] = con;
		abilityScores[3] = intel;
		abilityScores[4] = wis;
		abilityScores[5] = cha;
		for (int i = 0; i < 6; i++)
		{
			abilityBonuses[i] = 0;
		}
		maxHitPoints = 10;
		initAbilityModifiers();
		currentHitPoints = maxHitPoints;
		baseAttackBonus = 1;
		level = 1;
		int levelsToGo = lvl - level;
		while (levelsToGo > 0)
		{
			Dice hitDice = Dice();
			int healthRoll = hitDice.roll("1d10[+0]");
			levelUp(healthRoll);
			levelsToGo--;
		}
	}
};