//// WarzoneCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <conio.h>
#include "MapLoaderDriver.h"
#include "PlayerDriver.h"
#include "OrdersDriver.h"
#include "CardsDriver.h"
#include "GameEngine.h"
#include "Orders.h"
//
////Main method that contains all part to run at once
int main()
{
//
//	//Assignment 2
//	//Part 1 - Game Start 
//	cout << "======================================= Part 1  =======================================\n" << endl;
	GameEngine games;
	games.initGame();
//	cout << "======================================= Part 1 end =======================================\n" << endl;
//	
//	//Part 2 - StartUp Phase
//	cout << "======================================= Part 2  =======================================" << endl;
	StartUp startup;
	startup.setGameEngine(&games);
	startup.startupPhase();
	games.reinforcementPhase();
	games.issueOrderPhase();
	//games.executeOrdersPhase();

	auto result = _getch();
	return 0;
}
