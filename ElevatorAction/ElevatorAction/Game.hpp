#pragma once
#include "GameState.hpp"
#include "UserInput.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"
class UserInput;
class LevelManager;
class GameState;
class Game
{
public:
	LevelManager levels;
	UserInput input;
	GameState *gamestate;
	Player player = Player();

	Game();
	~Game();

	void keyboard_input(unsigned char key, int x, int y);
	void specialkey_input(int key, int x, int y);
	void set_gamestate(GameState *state);
	void game_over();
	void process(float delta);
	void render(float delta);
};

