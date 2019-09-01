#pragma once
#include "GameState.hpp"
class GameStateScoreboard :
	public GameState
{
public:
	GameStateScoreboard(Game *game);
	~GameStateScoreboard();

	void process(float delta) override;
	void render(float delta) override;
};

