#include <iostream>

#include "database.h"
#include "questionmc.h"
#include "questionsa.h"
#include "questiontf.h"

using namespace quiz;
using namespace std;

Database::Database(std::string path)
	:dbPath_(path)
{
}


Database::~Database()
{
	if (db_.is_open()) {
		db_.close();
	}
}


std::vector<std::shared_ptr<Question>> quiz::Database::readQuestions()
{
	vector<shared_ptr<Question>> questions;
	try
	{
		db_.open(dbPath_);

		if (!db_.is_open()) {
			throw invalid_argument("db not exists");
		}

		int questionsCount = getQuestionsCount();

		while (!db_.eof() && questions.size() < questionsCount)
		{
			shared_ptr<Question> question = readQuestion();
			questions.push_back(question);
		}
	}
	catch (...)
	{
		cout << "Error: can't open database  '" << dbPath_ << "'" << endl;
		throw invalid_argument("db not exists");
	}

	if (db_.is_open()) {
		db_.close();
	}

	return questions;
}


std::vector<std::string> Database::split(const std::string &text, char sep) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}


std::string quiz::Database::readNextLine()
{
	string line;
	if (!db_.eof()) {
		getline(db_, line);
	}
	else
	{
		throw invalid_argument("can't read db");
	}

	return line;
}


int quiz::Database::getQuestionsCount()
{
	string line = readNextLine();
	int questionsCount = stoi(line);

	return questionsCount;
}


std::shared_ptr<Question> quiz::Database::readQuestion()
{
	string line = readNextLine();
	vector<string> parts = split(line, ' ');

	if (parts.size() != 2) {
		throw invalid_argument("incorrect db format");
	}

	string questionType = parts[0];
	int questionPoints = stoi(parts[1]);

	if (questionPoints <= 0) {
		throw invalid_argument("incorrect points number");
	}

	shared_ptr<Question> question;
	if (questionType == "TF") {
		question = readQuestionTF(questionPoints);
	}
	else if (questionType == "MC") {
		question = readQuestionMC(questionPoints);
	}
	else if (questionType == "SA") {
		question = readQuestionSA(questionPoints);
	}
	else {
		throw invalid_argument("incorrect question type");
	}

	return question;
}


std::shared_ptr<Question> quiz::Database::readQuestionTF(const int points)
{
	string question = readNextLine();
	string answer = readNextLine();
	std::shared_ptr<Question> questionTF(new QuestionTF(question, answer, points));
	return questionTF;
}


std::shared_ptr<Question> quiz::Database::readQuestionSA(const int points)
{
	string question = readNextLine();
	string answer = readNextLine();
	return std::shared_ptr<Question>(new QuestionSA(question, answer, points));
}


std::shared_ptr<Question> quiz::Database::readQuestionMC(const int points)
{
	string question = readNextLine();
	int optionsNumber = stoi(readNextLine());
	if (optionsNumber < 0 || optionsNumber>6) {
		throw invalid_argument("incorrect options number");
	}

	vector<string> options;
	for (int i = 0; i < optionsNumber; i++) {
		options.push_back(readNextLine());
	}

	string answer = readNextLine();
	shared_ptr<QuestionMC> questionMC(new QuestionMC(question, answer, points));

	for (string option : options) {
		questionMC->addOption(option);
	}

	return questionMC;
}
