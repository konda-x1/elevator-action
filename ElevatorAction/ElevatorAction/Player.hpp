#pragma once
#include "Level.hpp"
#include "PlayerHitbox.hpp"
#include "UserInput.hpp"

class Level;
class PlayerHitbox;
class Player : public Usable
{
public:
	float fx, fy; // Coordinates of the lower left point of the player
	float width = 0.2f, height = 0.5f;
	Level *level = nullptr;
	PlayerHitbox *hitbox = nullptr;
	UserInput input;

	Player();
	Player(Level *level, float fx, float fy);
	~Player();

	void check_usable() override;
	void process(float delta);
	void render(float delta);
};

