#include "Player.hpp"



Player::Player()
{
}

Player::Player(Level *level, float x, float y): level(level), x(x), y(y)
{
}


Player::~Player()
{
}

void Player::check_usable()
{
	if (this->level == nullptr)
		throw std::exception("Level is null");
}

void Player::process(float delta)
{
	this->check_usable();
}

void Player::render(float delta)
{
	this->check_usable();
}
