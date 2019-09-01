#pragma once
#include "GameState.hpp"
class GameStateGameOver :
	public GameState
{
public:
	GameStateGameOver(Game *game);
	~GameStateGameOver();

	void process(float delta) override;
	void render(float delta) override;
};

