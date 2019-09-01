#pragma once
#include "Player.hpp"
#include "LevelManager.hpp"
class Game
{
	Player player = Player();
public:
	LevelManager levels = LevelManager();

	Game();
	~Game();

	void keyboard_input(unsigned char key, int x, int y);
	void specialkey_input(int key, int x, int y);
	bool is_game_over();
	void process(float delta);
	void render(float delta);
};

