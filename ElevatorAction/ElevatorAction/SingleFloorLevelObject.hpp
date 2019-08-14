#pragma once
#include "LevelObject.hpp"

class SingleFloorLevelObject : public LevelObject
{
public:
	int y;
	SingleFloorLevelObject(int x, int y);
	~SingleFloorLevelObject();
};

