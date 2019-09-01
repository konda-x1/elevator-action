#pragma once
#include "Level.hpp"
#include "PlayerHitbox.hpp"

class Level;
class PlayerHitbox;
class Player : public Usable
{
public:
	float fx, fy; // Coordinates of the lower left point of the player
	float width = 0.2f, height = 0.5f;
	Level *level = nullptr;
	PlayerHitbox *hitbox = nullptr;
	bool input_up = false;
	bool input_down = false;
	bool input_left = false;
	bool input_right = false;
	bool input_fire = false;

	Player();
	Player(Level *level, float fx, float fy);
	~Player();

	void check_usable() override;
	void reset_inputs();
	void process(float delta);
	void render(float delta);
};

