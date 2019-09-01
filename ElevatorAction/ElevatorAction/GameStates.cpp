#include "GameStates.hpp"


GameStates::GameStates()
{
}


GameStates::~GameStates()
{
}

GameStateMainMenu *GameStates::main_menu(Game *game)
{
	return new GameStateMainMenu(game);
}

GameStateScoreboard *GameStates::scoreboard(Game *game)
{
	return new GameStateScoreboard(game);
}

GameStateInGame *GameStates::in_game(Game *game)
{
	return new GameStateInGame(game);
}

GameStateGameOver *GameStates::game_over(Game *game)
{
	return new GameStateGameOver(game);
}

GameStateExit *GameStates::exit(Game *game)
{
	return new GameStateExit(game);
}
