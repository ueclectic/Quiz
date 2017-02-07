#include "questionTF.h"

using namespace quiz;


QuestionTF::QuestionTF(std::string questionContent, std::string correctAnswer, int points)
	:Question(questionContent, correctAnswer, points)
{
}

QuestionTF::~QuestionTF()
{
}

std::string quiz::QuestionTF::print() const
{
	return getQuestion();
}
