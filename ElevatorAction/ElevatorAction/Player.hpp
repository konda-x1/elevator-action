#pragma once
#include "Level.hpp"
class Player
{
public:
	float x, y;
	class Level *level = nullptr;

	Player();
	Player(Level *level, float x, float y);
	~Player();

	void check_usable();
	void process(float delta);
	void render(float delta);
};

