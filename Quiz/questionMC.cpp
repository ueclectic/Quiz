#include "questionmc.h"
#include <stdexcept>


using namespace std;
using namespace quiz;

QuestionMC::QuestionMC(std::string questionContent, std::string correctAnswer, int points)
	:Question(questionContent, correctAnswer, points)
{
}


QuestionMC::~QuestionMC()
{
}

std::string quiz::QuestionMC::print() const
{
	string output = getQuestion() + "\n";
	for (char i = 0; i < options_.size(); i++) {
		string index(1, 'A' + i);
		output += index + ") " + options_[i] + "\n";
	}


	return output;
}

Response quiz::QuestionMC::check(std::string input) const
{
	size_t inputLength = 1;
	if (input.empty() || input.size() != inputLength) {
		throw invalid_argument("invalid input");
	}

	char answer = toupper(input[0]);

	int index = answer - 'A';
	if (index < 0 || index >= options_.size()) {
		throw invalid_argument("out of range input");
	}

	string uppercaseInput(1, answer);

	return getResult(uppercaseInput, options_[index]);
}

void quiz::QuestionMC::addOption(std::string option)
{
	if (option.empty()) {
		throw invalid_argument("invalid option");
	}
	if (option.empty()) {
		throw invalid_argument("max number of options is 6");
	}

	options_.push_back(option);
}
