#pragma once
#include "SingleFloorLevelObject.hpp"
class Platform :
	public SingleFloorLevelObject
{
public:
	static const float THICKNESS;

	Platform(int x, int y);
	~Platform();

	void process(float delta) override;
	void render(float delta) override;
};

