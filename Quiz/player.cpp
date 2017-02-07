#include "player.h"

using namespace quiz;

Player::Player(std::string firstName, std::string lastName)
	:firstName_(firstName), lastName_(lastName), score_(0)
{
}

Player::~Player()
{
}

std::string Player::getFirstName() const
{
	return firstName_;
}

std::string Player::getLastName() const
{
	return lastName_;
}

int Player::getScore() const
{
	return score_;
}

void Player::addPoints(const int points)
{
	score_ += points;
	if (score_ < 0) {
		score_ = 0;
	}
}
