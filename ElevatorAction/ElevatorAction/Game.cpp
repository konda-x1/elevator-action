#include "Game.hpp"
#include "GameStates.hpp"
#include "glut/glut.h"



Game::Game() : input(UserInput()), levels(LevelManager(this)), gamestate(GameStates::in_game(this))
{
}


Game::~Game()
{
}

void Game::keyboard_input(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		this->input.up = true;
		break;
	case 's':
		this->input.down = true;
		break;
	case 'a':
		this->input.left = true;
		break;
	case 'd':
		this->input.right = true;
		break;
	case 'e':
	case ' ':
		this->input.use = true;
	}
}

void Game::specialkey_input(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		this->input.up = true;
		break;
	case GLUT_KEY_DOWN:
		this->input.down = true;
		break;
	case GLUT_KEY_LEFT:
		this->input.left = true;
		break;
	case GLUT_KEY_RIGHT:
		this->input.right = true;
		break;
	}
}

void Game::set_gamestate(GameState * state)
{
	delete this->gamestate;
	this->gamestate;
}

void Game::game_over()
{
	if (this->gamestate->state != GameState::IN_GAME)
		throw std::exception("Not in game");
	this->set_gamestate(GameStates::game_over(this));
}

void Game::process(float delta)
{
	this->gamestate->process(delta);
}

void Game::render(float delta)
{
	this->gamestate->render(delta);
}
