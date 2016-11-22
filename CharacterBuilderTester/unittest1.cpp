#include "stdafx.h"
#include "CppUnitTest.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include "CharacterCreator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharacterBuilderTester
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BullyBuilderTest) //tests a characterCreator using a bullyBuilder
		{
			BullyBuilder* bulBuild = new BullyBuilder();
			CharacterCreator charCreator;
			charCreator.setCharacterBuilder(bulBuild);
			charCreator.createCharacter(1);
			Character testChar = *charCreator.getCharacter();
			Assert::AreEqual(testChar.getLevel(), 1);
			bool goodstats = true;
			int* stats = testChar.getAbilityScores();
			if (*(stats + 0) < *(stats + 2)) //True if strength is lower than con
			{
				goodstats = false;
			}
			else if (*(stats + 2) < *(stats + 1)) //True if con is lower than dex
			{
				goodstats = false;
			}
			else if (*(stats + 1) < *(stats + 3)) //True if dex is lower than int
			{
				goodstats = false;
			}
			else if (*(stats + 3) < *(stats + 5)) //True if int is lower than cha
			{
				goodstats = false;
			}
			else if (*(stats + 5) < *(stats + 4)) //True if cha is lower than wis
			{
				goodstats = false;
			}
			Assert::AreEqual(true, goodstats);
		}

		TEST_METHOD(NimbleBuilderTest) //tests a characterCreator using a nimbleBuilder
		{
			NimbleBuilder* nimBuild = new NimbleBuilder();
			CharacterCreator charCreator;
			charCreator.setCharacterBuilder(nimBuild);
			charCreator.createCharacter(1);
			Character testChar = *charCreator.getCharacter();
			Assert::AreEqual(testChar.getLevel(), 1);
			bool goodstats = true;
			int* stats = testChar.getAbilityScores();
			if (*(stats + 1) < *(stats + 2)) //True if dex is lower than con
			{
				goodstats = false;
			}
			else if (*(stats + 2) < *(stats + 0)) //True if con is lower than strength
			{
				goodstats = false;
			}
			else if (*(stats + 0) < *(stats + 3)) //True if strength is lower than int
			{
				goodstats = false;
			}
			else if (*(stats + 3) < *(stats + 5)) //True if int is lower than cha
			{
				goodstats = false;
			}
			else if (*(stats + 5) < *(stats + 4)) //True if cha is lower than wis
			{
				goodstats = false;
			}
			Assert::AreEqual(true, goodstats);
		}

		TEST_METHOD(TankBuilderTest) //tests a characterCreator using a tankBuilder
		{
			TankBuilder* tankBuild = new TankBuilder();
			CharacterCreator charCreator;
			charCreator.setCharacterBuilder(tankBuild);
			charCreator.createCharacter(1);
			Character testChar = *charCreator.getCharacter();
			Assert::AreEqual(testChar.getLevel(), 1);
			bool goodstats = true;
			int* stats = testChar.getAbilityScores();
			if (*(stats + 2) < *(stats + 1)) //True if con is lower than dex
			{
				goodstats = false;
			}
			else if (*(stats + 1) < *(stats + 0)) //True if dex is lower than strength
			{
				goodstats = false;
			}
			else if (*(stats + 0) < *(stats + 3)) //True if strength is lower than int
			{
				goodstats = false;
			}
			else if (*(stats + 3) < *(stats + 5)) //True if int is lower than cha
			{
				goodstats = false;
			}
			else if (*(stats + 5) < *(stats + 4)) //True if cha is lower than wis
			{
				goodstats = false;
			}
			Assert::AreEqual(true, goodstats);
		}

		TEST_METHOD(HighLevelTest) //tests a characterCreator making a high level fighter
		{
			BullyBuilder* bulBuild = new BullyBuilder();
			CharacterCreator charCreator;
			charCreator.setCharacterBuilder(bulBuild);
			charCreator.createCharacter(10);
			Character testChar = *charCreator.getCharacter();
			Assert::AreEqual(testChar.getLevel(), 10);
			int* stats = testChar.getAbilityScores();
			int hitBonus = floor(*(stats + 0) / 2) - 5;	
			hitBonus += 10;
			Assert::AreEqual(testChar.toHit(0), hitBonus);
		}

	};
}