#include "questionsa.h"
#include <stdexcept>

using namespace std;
using namespace quiz;

QuestionSA::QuestionSA(std::string questionContent, std::string correctAnswer, int points)
	:Question(questionContent, correctAnswer, points)
{
}


QuestionSA::~QuestionSA()
{
}

std::string quiz::QuestionSA::print(int number) const
{
	return getQuestion(number)+"\n";
}

Response quiz::QuestionSA::check(std::string input) const
{
	if (input.empty()) {
		throw invalid_argument("invalid input");
	}

	return getResult(input, getAnswer());
}
