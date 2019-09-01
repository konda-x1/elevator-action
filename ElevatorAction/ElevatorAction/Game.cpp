#include "Game.hpp"



Game::Game()
{
}


Game::~Game()
{
}

void Game::keyboard_input(unsigned char key, int x, int y)
{
}

void Game::specialkey_input(int key, int x, int y)
{
}

bool Game::is_game_over()
{
	return this->levels.is_game_over();
}

void Game::process(float delta)
{
	this->levels.process(delta);
}

void Game::render(float delta)
{
	this->levels.render(delta);
}
