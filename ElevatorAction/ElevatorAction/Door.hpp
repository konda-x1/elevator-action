#pragma once
#include "SingleFloorLevelObject.hpp"
#include "Hitbox.hpp"
class Door :
	public SingleFloorLevelObject
{
	bool open = false;
	float open_elapsed = 0.0f;
public:
	static const float WIDTH;
	static const float HEIGHT;
	class Hitbox *hitbox;

	float r;
	float g;
	float b;
	Door(int x, int y, float r, float g, float b);
	~Door();

	virtual void render_background();
	virtual void render_closed();
	virtual void render_halfopen();
	virtual void render_open();
	void render(float delta) override;
	void process(float delta) override;
};

