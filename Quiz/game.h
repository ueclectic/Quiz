#pragma once
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "player.h"
#include "question.h"


namespace quiz {

	class Game
	{
	public:
		Game();
		~Game();
		void start();

	private:
		std::unique_ptr<Player> player_;
		std::vector<std::shared_ptr<Question>> questions_;
		std::string dbPath_;

		void createPlayer();
		int getQuizSize(int maxSize);
		std::vector<int> generateRandomIndexes(int maxSize);
		Response checkUserInput(std::shared_ptr<Question> question);

	};

}

