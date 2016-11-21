#include "stdafx.h"
#include "CppUnitTest.h"
#include "BullyBuilder.h"
#include "CharacterCreator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharacterBuilderTester
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BullyBuilderTest)
		{
			BullyBuilder* bulBuild = new BullyBuilder();
			CharacterCreator charCreator;
			charCreator.setCharacterBuilder(bulBuild);
			charCreator.createCharacter(1);
			Character testChar = *charCreator.getCharacter();
			Assert::AreEqual(testChar.getLevel(), 1);
			bool goodstats = false;
			int* stats = testChar.getAbilityScores();
			int test = *(stats + 1);
		}

	};
}