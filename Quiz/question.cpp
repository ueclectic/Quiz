#include "question.h"

using namespace quiz;

Question::Question(std::string questionContent, std::string correctAnswer, int points)
	:question_(questionContent), answer_(correctAnswer), points_(points)
{
}


Question::~Question()
{
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
