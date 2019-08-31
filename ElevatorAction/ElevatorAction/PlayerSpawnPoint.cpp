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
	player->fx = (float)this->x - 0.5f - player->width / 2.0f;
	player->fy = (float)this->y - 1.0f + Platform::THICKNESS;
	return player;
}

void PlayerSpawnPoint::process(float delta, Player *player)
{
}

void PlayerSpawnPoint::render(float delta)
{
}
