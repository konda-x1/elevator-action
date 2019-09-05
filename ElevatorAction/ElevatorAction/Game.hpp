#pragma once
#include <vector>
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
	Player *player = new Player();
	std::vector<int> scores = std::vector<int>();

	Game();
	~Game();

	void keyboard_press(unsigned char key, int x, int y);
	void keyboard_release(unsigned char key, int x, int y);
	void specialkey_press(int key, int x, int y);
	void specialkey_release(int key, int x, int y);
	void set_gamestate(GameState *state);
	void game_over();
	void process(float delta);
	void render(float delta);
};

