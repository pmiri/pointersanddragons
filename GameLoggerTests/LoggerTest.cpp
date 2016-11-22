#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

#include "../comp345game/GameLogger.h"
#include "../comp345game/Dice.h"
#include "../comp345game/GameLogger.cpp"
#include "../comp345game/Dice.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameLoggerTests
{		
	TEST_CLASS(LoggerTest)
	{
	public:
		
		TEST_METHOD(LogDiceTest)
		{
			GameLogger* logger = new GameLogger();
			Dice* d = new Dice();
			d->Connect(logger);
			int value = d->roll("4d6[+3]");

			ifstream file;
			file.open(logger->getPath());
			Assert::IsTrue(file.is_open());
			
			string content;
			getline(file, content);
			Assert::AreEqual(content, "Rolled a " + to_string(value));

			file.close();
			delete logger;
			delete d;
		}

		TEST_METHOD(LogFileTest)
		{
			string message = "TEST MESSAGE";
			GameLogger* logger = new GameLogger();
			logger->Log(message);

			ifstream file;
			file.open(logger->getPath());
			Assert::IsTrue(file.is_open());

			string content;
			getline(file, content);
			Assert::AreEqual(content, message);

			file.close();
			delete logger;
		}

	};
}