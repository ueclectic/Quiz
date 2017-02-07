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

Response quiz::Question::check(std::string input) const
{
	//Todo: check input

	const string points = to_string(getPoints());
	if (input == getAnswer()) {
		return Response("Correct! You get " + points + " points.", getPoints());
	}
	else
	{
		return Response("Incorrect, the answer was '" + getAnswer() + "'. You lose " + points + " points.", -getPoints());
	}
}


inline std::string Question::getQuestion() const
{
	return question_;
}


std::string Question::getAnswer() const
{
	return answer_;
}


int Question::getPoints() const
{
	return points_;
}