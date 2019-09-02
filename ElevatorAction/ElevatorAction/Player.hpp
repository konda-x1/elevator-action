#pragma once
#include "Level.hpp"
#include "PlayerHitbox.hpp"
#include "UserInput.hpp"

class Level;
class PlayerHitbox;
class Elevator;
class Player : public Usable
{
	std::pair<float, float> process_player_commands();
	void elapse_jump(float delta);
public:
	float fx, fy; // Coordinates of the lower left point of the player
	float width = 0.2f, height = 0.5f;
	float velx = 0.0f, vely = 0.0f;
	float movement_speed = 1.0f;
	float jump_speed = 1.2f;
	float jump_elapsed = 0.0f;
	float jump_cooldown = 2.0f;
	bool on_ground = false;
	bool jumping = false;
	Level *level = nullptr;
	PlayerHitbox *hitbox = nullptr;
	UserInput *input = nullptr;
	Elevator *elevator = nullptr;

	Player();
	Player(Level *level, float fx, float fy);
	~Player();

	float dfx(float delta);
	float dfy(float delta);
	float current_height();
	bool inside_elevator();
	void check_usable() override;
	void process(float delta);
	void render(float delta);
};

