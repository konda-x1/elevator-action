#pragma once
#include "MapObject.hpp"

class Elevator : public MapObject
{
	float wait_time = 2.0f;
	float wait_time_elapsed = 0.0f;
	int passive_direction; //1 == up, -1 == down

	void move_next();
public:
	float fy;
	int min_floor;
	int max_floor;
	int target_floor;
	float vspeed; // Floors per second

	Elevator(int x, int min_floor, int max_floor, float vspeed = 1.0f);
	~Elevator();

	int current_floor();
	bool is_moving();
	bool move_up();
	bool move_down();
	bool move_generic(int direction);
	int direction();
	void process(float delta) override;
	void render(float delta) override;
};

