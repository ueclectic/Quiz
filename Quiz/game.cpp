#include <iostream>

#include "game.h"
#include "questionmc.h"
#include "questionsa.h"
#include "questiontf.h"

using namespace std;
using namespace quiz;



Game::Game()
{
}

Game::~Game()
{
}

void quiz::Game::start()
{
	try
	{
		createPlayer();
	}
	catch (...)
	{
		cout <<endl<< "Game unexpectedly finished" << endl;
	}

}

void quiz::Game::createPlayer()
{
	cout << "What is your first name?" << endl;
	string firstName;
	cin >> firstName;

	cout << endl<<"What is your last name?" << endl;
	string lastName;
	cin >> lastName;

	player_ = unique_ptr<Player>(new Player(firstName, lastName));
}

