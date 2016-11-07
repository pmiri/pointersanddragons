//! @file 
//! @brief	This file contains all of the unit tests made using CppUnitTestFramework.
//!			To run the tests, please use Visual Studio 2015's Test Explorer
//!

#include "stdafx.h"
#include "CppUnitTest.h"
//Need to include all cpp files used in test or else LNK2019 error occurs
#include "..\comp345game\Map.cpp"
#include "..\comp345game\MapUI.cpp"
#include "..\comp345game\Observable.cpp"
#include "..\comp345game\Observer.cpp"

//http://stackoverflow.com/questions/19886397/how-to-solve-the-error-lnk2019-unresolved-external-symbol-function

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace A1NativeUnitTestProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//! Test method to test the attaching of an observer to the map works
		TEST_METHOD(TestObserverLink)
		{
			Map* map = new Map(5, 5);
			MapUI* mapUI = new MapUI(map);

			list<Observer*> observers = map->getObservers();
			for each (Observer *obs in observers)
			{
				if (obs == mapUI) {
					Assert::IsTrue(true);
					break;
				}
			}
			delete map;
			delete mapUI;
		}

		//! Test method to test that the observer is notifed when the observable does certain actions
		TEST_METHOD(TestNotify)
		{
			Map* map = new Map(5, 5);
			MapUI* mapUI = new MapUI(map);
			string tempMapString = "";

			map->setEntrance(0, 0);
			map->setExit(4, 4);

			map->fillCell(0, 1, 'W');
			tempMapString = mapUI->getMapString();
			map->fillCell(0, 2, 'W');
			Assert::IsFalse(tempMapString == mapUI->getMapString());
		}

	};
}