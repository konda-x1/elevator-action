#pragma once
#include "SingleFloorLevelObject.hpp"
class PlayerSpawnPoint :
	public SingleFloorLevelObject
{
public:
	PlayerSpawnPoint(int x, int y);
	~PlayerSpawnPoint();

	void process(float delta) override;
	void render(float delta) override;
};

