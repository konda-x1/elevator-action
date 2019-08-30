#pragma once
#include "SingleFloorLevelObject.hpp"
#include "Player.hpp"
class SingleFloorLevelObject;
class PlayerSpawnPoint :
	public SingleFloorLevelObject
{
public:
	PlayerSpawnPoint(int x, int y);
	~PlayerSpawnPoint();

	class Player *spawn(class Level *level, Player *player);
	void process(float delta, Player *player) override;
	void render(float delta) override;
};

