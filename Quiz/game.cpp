#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <stdexcept>

#include "game.h"
#include "questionmc.h"
#include "questionsa.h"
#include "questiontf.h"
#include "database.h"

using namespace std;
using namespace quiz;


void quiz::Game::start()
{
	try
	{
		createPlayer();

		getDatabasePath();
		Database database(dbPath_);

		questions_ = database.readQuestions();

		int quizSize = getQuizSize(questions_.size());
		vector<int> randomIndexes = generateRandomIndexes(questions_.size());

		for (int i = 0; i < quizSize; i++) {
			int curIndex = randomIndexes[i];
			cout << endl << questions_[curIndex]->print(i + 1);

			Response response = checkUserInput(questions_[curIndex]);
			cout << response.MESSAGE << endl;
			player_->addPoints(response.VALUE);
		}

		printFooter();
	}
	catch (...)
	{
		cout << endl << "Game unexpectedly finished" << endl;
	}
}


void quiz::Game::createPlayer()
{
	cout << "What is your first name?" << endl;
	string firstName;
	cin >> firstName;

	cout << endl << "What is your last name?" << endl;
	string lastName;
	cin >> lastName;

	player_ = unique_ptr<Player>(new Player(firstName, lastName));
}

void quiz::Game::getDatabasePath()
{
	cout << endl << "What file stores your questions?" << endl;
	cin >> dbPath_;
}

int quiz::Game::getQuizSize(int maxSize)
{
	while (true) {

		try {
			cout << endl << "How many questions would you like (out of " << maxSize << ")?" << endl;
			int quizSize = 0;
			string input;
			cin >> input;
			quizSize = stoi(input);

			if (quizSize < 1) {
				throw invalid_argument("invalid quiz size");
			}
			else if (quizSize > maxSize) {
				cout << "Sorry, that is too many." << endl;
				continue;
			}

			return quizSize;
		}
		catch (...) {
			cout << "Sorry, that is not valid." << endl;
		}
	}
}

std::vector<int> quiz::Game::generateRandomIndexes(int maxSize)
{
	vector<int> indexes;
	for (int i = 0; i < maxSize; i++) {
		indexes.push_back(i);
	}

	std::srand(unsigned(std::time(0)));
	random_shuffle(begin(indexes), end(indexes));

	return indexes;
}

Response quiz::Game::checkUserInput(std::shared_ptr<Question> question)
{
	while (true)
	{
		cout << endl << "Answer: ";
		try {
			string answer;
			cin >> answer;
			return question->check(answer);
		}
		catch (...) {
			cout << "Incorrect input. Please try again" << endl;
		}
	}
}

void quiz::Game::printFooter()
{
	cout << endl << endl << player_->getFirstName() << " " << player_->getLastName() << ", your game is over!" << endl;
	cout << "You final score is " << player_->getScore() << " points. " << endl;
	cout << "Better luck next time!" << endl << endl;
}



Game::Game()
{
}

Game::~Game()
{
}
