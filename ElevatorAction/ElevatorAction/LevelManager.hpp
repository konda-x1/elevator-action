#pragma once
#include <vector>
#include "Level.hpp"
class LevelManager
{
	std::vector<Level *> levels = std::vector<Level *>();
	int current_index = 0;
	bool game_over;

	Level *current();
public:
	LevelManager();
	~LevelManager();

	void add(Level *level);
	bool go2next();
	bool is_game_over() const;

	void process(float delta);
	void render(float delta);
};

