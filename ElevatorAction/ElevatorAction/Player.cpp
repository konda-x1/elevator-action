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

void Player::reset_inputs()
{
	this->input_up = false;
	this->input_down = false;
	this->input_left = false;
	this->input_right = false;
	this->input_fire = false;
}

void Player::process(float delta)
{
	this->check_usable();

	this->reset_inputs();
}

void Player::render(float delta)
{
	this->check_usable();
	this->hitbox->render(delta, 0.0f, 0.8f, 0.0f);
}
