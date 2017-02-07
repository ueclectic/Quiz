#pragma once
#include <string>
#include "response.h"

namespace quiz {

	class Question
	{

	public:
		Question(std::string questionContent, std::string correctAnswer, int points);
		virtual ~Question();

		virtual std::string print(int number) const = 0;
		virtual Response check(std::string input) const = 0;

	protected:
		std::string getQuestion(int number) const;
		std::string getAnswer() const;
		int getPoints() const;
		Response getResult(std::string input, std::string correctAnswer) const;

	private:
		std::string question_;
		std::string answer_;
		int points_;
	};

}

