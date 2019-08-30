#pragma once
#include "Level.hpp"
class Player : public Usable
{
public:
	float x, y;
	class Level *level = nullptr;

	Player();
	Player(Level *level, float x, float y);
	~Player();

	void check_usable() override;
	void process(float delta);
	void render(float delta);
};

