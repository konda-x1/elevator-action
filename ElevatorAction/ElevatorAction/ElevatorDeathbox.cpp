#include <cmath>
#include "ElevatorDeathbox.hpp"


ElevatorDeathbox::ElevatorDeathbox(Elevator * elevator) : AbstractHitbox(false), elevator(elevator)
{
}

ElevatorDeathbox::~ElevatorDeathbox()
{
}

float ElevatorDeathbox::x1() const
{
	return (float)this->elevator->x - 1.0f;
}

float ElevatorDeathbox::y1() const
{
	return std::ceil(this->elevator->fy - 1.0f - Platform::THICKNESS * 0.5f) - 1.0f + Platform::THICKNESS * 0.5f;
}

float ElevatorDeathbox::x2() const
{
	return (float)this->elevator->x;
}

float ElevatorDeathbox::y2() const
{
	return (float)this->elevator->min_floor - 1.0f;
}
