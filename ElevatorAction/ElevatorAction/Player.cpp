#include "Player.hpp"



Player::Player()
{
	this->hitbox = new PlayerHitbox(this);
}

Player::Player(Level *level, float fx, float fy): level(level), fx(fx), fy(fy)
{
	Player();
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
	this->hitbox->render(delta, 0.0f, 0.8f, 0.0f);
}
