#pragma once
#include "question.h"

namespace quiz {

	class QuestionSA :
		public Question
	{
	public:
		QuestionSA(std::string questionContent, std::string correctAnswer, int points);
		~QuestionSA();

		std::string print() const;
		Response check(std::string input) const;
	};

}

