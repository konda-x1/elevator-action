#pragma once
#include "MapObject.hpp"

class SingleFloorMapObject : public MapObject
{
public:
	int y;
	SingleFloorMapObject(int x, int y);
	~SingleFloorMapObject();
};

