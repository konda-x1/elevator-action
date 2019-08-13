#include "Elevator.hpp"
#include "util.hpp"

Elevator::Elevator(int x, int min_floor, int max_floor) : MapObject(x), min_floor(min_floor), max_floor(max_floor)
{
	int start_floor = randint(min_floor, max_floor);
	this->fy = (float)start_floor;
	this->target_floor = start_floor;
}

Elevator::~Elevator()
{
}

int Elevator::current_floor()
{
	return (int)this->fy;
}

bool Elevator::is_moving()
{
	return this->current_floor() != this->target_floor;
}

bool Elevator::move_up()
{
	if (this->is_moving() || this->current_floor() >= this->max_floor)
		return false;
	else
		this->target_floor = this->current_floor() + 1;
	return true;
}

bool Elevator::move_down()
{
	if (this->is_moving() || this->current_floor() <= this->min_floor)
		return false;
	else
		this->target_floor = this->current_floor() - 1;
	return true;
}

void Elevator::process(float delta)
{
}

void Elevator::render(float delta)
{
}
