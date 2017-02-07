#pragma once
#include <vector>
#include <string>
#include <memory>
#include <fstream>

#include "question.h"
#include "questionmc.h"
#include "questionsa.h"
#include "questiontf.h"

namespace quiz {

	class Database
	{
	public:
		Database(std::string path);
		~Database();
		std::vector<std::shared_ptr<Question>> readQuestions();
	private:
		std::string dbPath_;
		std::ifstream db_;
		std::vector<std::string> split(const std::string &text, char sep);
		std::string readNextLine();
		int getQuestionsCount();
		std::shared_ptr<Question> readQuestion();
		std::shared_ptr<Question> readQuestionTF(const int points);
		std::shared_ptr<Question> readQuestionSA(const int points);
		std::shared_ptr<Question> readQuestionMC(const int points);
	};

}
