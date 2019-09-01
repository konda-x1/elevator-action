#pragma once
#include "GameState.hpp"
class GameStateMainMenu :
	public GameState
{
public:
	GameStateMainMenu(Game *game);
	~GameStateMainMenu();

	void process(float delta) override;
	void render(float delta) override;
};

