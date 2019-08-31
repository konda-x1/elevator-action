#pragma once
#include "LevelObject.hpp"
#include "ElevatorHitbox.hpp"
#include "ElevatorDeathbox.hpp"

class ElevatorHitbox;
class ElevatorDeathbox;
class Elevator : public LevelObject
{
	float wait_time = 2.0f;
	float wait_time_elapsed = 0.0f;
	int passive_direction; //1 == up, -1 == down

	ElevatorHitbox *make_hitbox_inside();
	void init_hitboxes();
	void move_next();
public:
	static const float R;
	static const float G;
	static const float B;

	float fy;
	int min_floor;
	int max_floor;
	int target_floor;
	float vspeed; // Floors per second
	ElevatorHitbox *hitbox_bottom = nullptr;
	ElevatorHitbox *hitbox_top = nullptr;
	ElevatorHitbox *hitbox_inside = nullptr;
	ElevatorDeathbox *hitbox_death = nullptr;

	Elevator(int x, int min_floor, int max_floor, bool initially_active = false, float vspeed = 1.0f);
	~Elevator();

	int current_floor();
	bool is_moving();
	bool move_up();
	bool move_down();
	bool move_generic(int direction);
	int direction();
	void process(float delta, Player *player) override;
	void render(float delta) override;
};

