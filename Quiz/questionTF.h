#pragma once
#include "question.h"

namespace quiz {

	class QuestionTF :
		public Question
	{
	public:
		QuestionTF(std::string questionContent, std::string correctAnswer, int points);
		~QuestionTF();

		std::string print(int number) const;
		Response check(std::string input) const;
	};

}

