#pragma once
#include <string>
#include "response.h"

namespace quiz {

	class Question
	{

	public:
		Question(std::string questionContent, std::string correctAnswer, int points);
		virtual ~Question();

		virtual std::string print() const = 0;
		virtual Response check(std::string input) const;

	protected:
		inline std::string getQuestion() const;
		std::string getAnswer() const;
		int getPoints() const;

	private:
		std::string question_;
		std::string answer_;
		int points_;
	};

}

