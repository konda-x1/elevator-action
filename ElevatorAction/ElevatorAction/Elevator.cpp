#include <assert.h>
#include <cmath>
#include "Elevator.hpp"
#include "util.hpp"

void Elevator::move_next()
{
	assert(this->max_floor > this->min_floor);
	assert(this->is_moving() == false);

	int next_floor = this->current_floor() + this->passive_direction;
	if (next_floor > this->max_floor || next_floor < this->min_floor)
		this->passive_direction *= -1;

	this->move_generic(this->passive_direction);
}

Elevator::Elevator(int x, int min_floor, int max_floor, float vspeed) : MapObject(x), min_floor(min_floor), max_floor(max_floor), vspeed(vspeed)
{
	int start_floor = randint(min_floor, max_floor);
	this->fy = (float)start_floor;
	this->target_floor = start_floor;

	this->passive_direction = (randint(0, 1) == 0 ? -1 : 1);
}

Elevator::~Elevator()
{
}

int Elevator::current_floor()
{
	if (abs((float)this->target_floor - this->fy) < 0.01f)
		return this->target_floor;
	float trunc_val = (this->direction() == 1 ? std::floor(this->fy) : std::ceil(this->fy));
	return (int)trunc_val;
}

bool Elevator::is_moving()
{
	return this->current_floor() != this->target_floor;
}

bool Elevator::move_up()
{
	if (this->is_moving() || this->current_floor() >= this->max_floor)
		return false;
	else {
		this->target_floor = this->current_floor() + 1;
		this->passive_direction = 1;
	}
	return true;
}

bool Elevator::move_down()
{
	if (this->is_moving() || this->current_floor() <= this->min_floor)
		return false;
	else {
		this->target_floor = this->current_floor() - 1;
		this->passive_direction = -1;
	}
	return true;
}

bool Elevator::move_generic(int direction)
{
	assert(direction == 1 || direction == -1);
	if (direction == 1)
		return this->move_up();
	else
		return this->move_down();
}

int Elevator::direction()
{
	float diff = (float)this->target_floor - this->fy;
	if (diff > 0)
		return 1;
	else if (diff < 0)
		return -1;
	else
		return this->passive_direction;
}

void Elevator::process(float delta)
{
	if (this->is_moving()) {
		float sign = (float)this->direction();
		this->fy += sign * this->vspeed * delta;

		// Correct the fy value to match the exact value of current_floor when elevator stops moving
		if (!this->is_moving()) {
			this->fy = (float)this->current_floor();
		}
	}
	else {
		this->wait_time_elapsed += delta;
		if (this->wait_time_elapsed >= this->wait_time) {
			this->wait_time_elapsed = 0.0f;
			this->move_next();
		}
	}
}

void Elevator::render(float delta)
{
}
