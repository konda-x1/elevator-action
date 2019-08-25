#include "ElevatorHitbox.hpp"
#include "Platform.hpp"
#include <exception>


ElevatorHitbox::ElevatorHitbox(Elevator *elevator, float offset_y, bool solid) : AbstractHitbox(solid), elevator(elevator), offset_y(offset_y)
{
	if (elevator == nullptr)
		throw std::invalid_argument("Elevator cannot be null.");
}


ElevatorHitbox::~ElevatorHitbox()
{
}

float ElevatorHitbox::x1() const
{
	return (float)this->elevator->x - 1.0f;
}

float ElevatorHitbox::y1() const
{
	return this->elevator->fy - 1.0f + Platform::THICKNESS + this->offset_y;
}

float ElevatorHitbox::x2() const
{
	return (float)this->elevator->x;
}

float ElevatorHitbox::y2() const
{
	return this->elevator->fy - 1.0f + this->offset_y;
}
