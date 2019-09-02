#include <iostream>
#include "GameStateInGame.hpp"

GameStateInGame::GameStateInGame(Game *game) : GameState(game, GAME_OVER)
{
}


GameStateInGame::~GameStateInGame()
{
}

void GameStateInGame::process(float delta)
{
	this->game->levels.process(delta);
}

void GameStateInGame::render(float delta)
{
	this->game->levels.render(delta);
}
