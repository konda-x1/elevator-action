#include "Platform.hpp"
#include "Hitbox.hpp"

const float Platform::THICKNESS = 0.1f;

Platform::Platform(int x, int y) : SingleFloorLevelObject(x, y)
{
	this->hitboxes.push_back(Hitbox::platform(x, y));
}

Platform::~Platform()
{
}

void Platform::process(float delta)
{
}

void Platform::render(float delta)
{
}
