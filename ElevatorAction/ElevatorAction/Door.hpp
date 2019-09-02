#pragma once
#include "SingleFloorLevelObject.hpp"
#include "Hitbox.hpp"

class Door :
	public SingleFloorLevelObject
{
	bool open = false;
	bool activated = false;
	float open_elapsed = 0.0f;
public:
	static const float WIDTH;
	static const float HEIGHT;
	static const float WINDOW_FRAME_WIDTH;
	static const float KNOB_WIDTH;
	Hitbox *hitbox;

	float r;
	float g;
	float b;
	Door(int x, int y, float r, float g, float b);
	~Door();

	void opendoor();
	virtual void activate(Player *player);
	virtual void render_background();
	virtual void render_doorknob(float right);
	virtual void render_closed();
	virtual void render_halfopen();
	virtual void render_open();
	void render(float delta) override;
	void process(float delta, Player *player) override;
};

