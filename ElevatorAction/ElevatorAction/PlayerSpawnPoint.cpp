#include "PlayerSpawnPoint.hpp"


PlayerSpawnPoint::PlayerSpawnPoint(int x, int y) : SingleFloorLevelObject(x, y)
{
}

PlayerSpawnPoint::~PlayerSpawnPoint()
{
}

Player * PlayerSpawnPoint::spawn(Level *level, Player * player = nullptr)
{
	if (player == nullptr) {
		player = new Player();
	}
	player->level = level;
	player->x = (float)this->x - 1.0f;
	player->y = (float)this->y;
	return player;
}

void PlayerSpawnPoint::process(float delta)
{
}

void PlayerSpawnPoint::render(float delta)
{
}
