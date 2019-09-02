#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "util.hpp"
#include "CollisionHelper.hpp"
#include "Door.hpp"


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

float Player::dfx(float delta)
{
	return this->velx * delta;
}

float Player::dfy(float delta)
{
	return this->vely * delta;
}

float Player::current_height()
{
	if (this->input->down && !this->inside_elevator())
		return this->height / 2.0f;
	return this->height;
}

bool Player::inside_elevator()
{
	return this->elevator != nullptr;
}

bool Player::near_door()
{
	return this->door != nullptr;
}

void Player::die()
{
	--this->lives;
	this->level->kill_player();
}

void Player::check_usable()
{
	if (this->level == nullptr)
		throw std::exception("Level is null");
}

std::pair<float, float> Player::process_player_commands()
{
	this->input = &this->level->manager->game->input;
	float dirx = 0.0f, diry = 0.0f;
	if (this->input->left)
		dirx -= 1.0f;
	if (this->input->right) {
		dirx += 1.0f;
		//std::cout << "right" << std::endl;
	}
	if (this->input->up) {
		//std::cout << "lele" << std::endl;
		if (this->inside_elevator()) {
			this->elevator->move_up();
		}
		else {
			diry += 1.0f;
		}
	}
	else if (this->input->down && this->inside_elevator()) {
		this->elevator->move_down();
	}

	if (this->input->use) {
		if (this->near_door()) {
			this->door->opendoor();
		}
	}

	//std::cout << this->input->right << std::endl;
	return std::make_pair(dirx, diry);
}

void Player::elapse_jump(float delta)
{
	if (this->jumping) {
		this->jump_elapsed += delta;
		if (this->jump_elapsed > this->jump_cooldown) {
			this->jump_elapsed = 0.0f;
			this->jumping = false;
		}
	}
}

void Player::process(float delta)
{
	this->check_usable();

	this->elapse_jump(delta);

	std::pair<float, float> dirxy = this->process_player_commands();
	float dirx = dirxy.first;
	float diry = dirxy.second;

	if (/*!this->on_ground ||*/ this->jumping) {
		diry = 0.0f;
		//std::cout << "!onground" << std::endl;
	}

	//v2normalize(&dirx, &diry);
	if (diry > 0) {
		this->jumping = true;
	}
	
	// Add movement direction's effect to player velocity
	this->velx = dirx * movement_speed;
	if(diry > 0.0f)
		this->vely = diry * jump_speed;

	// Subtract gravity
	this->vely -= std::fmax(2.0f, abs(this->vely)) * delta;
	if (this->vely < -2.0f)
		this->vely = -2.0f;
	//std::cout << this->velx << " " << this->vely << std::endl;

	float current_fy = this->fy;
	//std::cout << this->dfx(delta) << " " << this->dfy(delta) << std::endl;
	this->level->move_player(this->dfx(delta), this->dfy(delta));
	//std::cout << this->fx << std::endl;
	this->on_ground = current_fy == this->fy;
	if (this->on_ground) {
		//std::cout << "onground" << std::endl;
	}


	// Reset velocities after movement
	this->velx = 0.0f;
}

void Player::render(float delta)
{
	this->check_usable();

	this->hitbox->render(delta, 0.0f, 0.8f, 0.0f);
}
