#pragma once
#include "SingleFloorLevelObject.hpp"
#include "Player.hpp"
class PlayerSpawnPoint :
	public SingleFloorLevelObject
{
public:
	PlayerSpawnPoint(int x, int y);
	~PlayerSpawnPoint();

	class Player *spawn(class Level *level, Player *player);
	void process(float delta) override;
	void render(float delta) override;
};

