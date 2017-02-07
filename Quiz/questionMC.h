#pragma once
#include "question.h"
#include <vector>

namespace quiz {

	class QuestionMC :
		public Question
	{
	public:
		QuestionMC(std::string questionContent, std::string correctAnswer, int points);
		~QuestionMC();

		std::string print() const;
		Response check(std::string input) const;
		void addOption(std::string option);
	private:
		std::vector<std::string> options_;
	};

}

