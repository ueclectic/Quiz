#include "questiontf.h"
#include <stdexcept>

using namespace std;
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
	return getQuestion()+"\n";
}

Response quiz::QuestionTF::check(std::string input) const
{
	//Todo: check input

	if (!(input == "true" || input == "false"))
	{
		throw invalid_argument("invalid input");
	}

	return getResult(input, getAnswer());
}
