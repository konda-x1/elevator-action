#pragma once
#include "MapObject.hpp"

class Elevator : public MapObject
{
public:
	float fy;
	int min_floor;
	int max_floor;
	int target_floor;

	Elevator(int x, int min_floor, int max_floor);
	~Elevator();

	int current_floor();
	bool is_moving();
	bool move_up();
	bool move_down();
	void process(float delta) override;
	void render(float delta) override;
};

