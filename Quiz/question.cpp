#include "question.h"

using namespace quiz;
using namespace std;

Question::Question(std::string questionContent, std::string correctAnswer, int points)
	:question_(questionContent), answer_(correctAnswer), points_(points)
{
}


Question::~Question()
{
}


std::string Question::getQuestion(int number) const
{
	string header = "Question " + to_string(number) + " (" + to_string(getPoints()) + " points)\n";
	return header + question_;
}


std::string Question::getAnswer() const
{
	return answer_;
}


int Question::getPoints() const
{
	return points_;
}

Response quiz::Question::getResult(std::string input, std::string correctAnswer) const
{
	const string points = to_string(getPoints());
	if (input == getAnswer()) {
		return Response("Correct! You get " + points + " points.", getPoints());
	}
	else
	{
		return Response("Incorrect, the answer was '" + correctAnswer + "'. You lose " + points + " points.", -getPoints());
	}
}
