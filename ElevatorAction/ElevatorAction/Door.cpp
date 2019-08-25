#include "util.hpp"
#include "Door.hpp"

const float Door::WIDTH = 0.6f;
const float Door::HEIGHT = 0.8f;

Door::Door(int x, int y, float r, float g, float b): SingleFloorLevelObject(x, y), r(r), g(g), b(b)
{
	float x1 = to_x1(x, y, Door::WIDTH, Door::HEIGHT);
	float y1 = to_y1(x, y, Door::WIDTH, Door::HEIGHT);
	float x2 = to_x2(x, y, Door::WIDTH, Door::HEIGHT);
	float y2 = to_y2(x, y, Door::WIDTH, Door::HEIGHT);
	this->hitbox = new Hitbox(x1, y1, x2, y2, false);
	this->hitboxes.push_back(this->hitbox);
}


Door::~Door()
{
}

void Door::render_background()
{
	this->render_hitboxes(0.0f, 0.0f, 0.0f, 0.0f);
}

void Door::render_closed()
{
}

void Door::render_halfopen()
{
}

void Door::render_open()
{
}

void Door::render(float delta)
{
	this->render_background();
	if (!this->open)
		this->render_closed();
	else if (this->open_elapsed < 0.15f)
		this->render_halfopen();
	else if (this->open_elapsed < 0.85f)
		this->render_open();
	else if (this->open_elapsed < 1.0f)
		this->render_halfopen();
}

void Door::process(float delta)
{
	if (this->open)
		this->open_elapsed += delta;
	if (this->open_elapsed >= 1.0f)
		this->open_elapsed = 0.0f;
}
