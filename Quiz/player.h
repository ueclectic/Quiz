#pragma once
#include <string>

namespace quiz {

	class Player
	{
	public:
		Player(std::string firstName, std::string lastName);
		~Player();

		std::string getFirstName() const;
		std::string getLastName() const;
		int getScore() const;
		void addPoints(const int points);
	private:
		std::string firstName_;
		std::string lastName_;
		int score_;
	};

}

