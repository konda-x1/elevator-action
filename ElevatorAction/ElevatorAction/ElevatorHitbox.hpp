#pragma once
#include "AbstractHitbox.hpp"
#include "Elevator.hpp"
class ElevatorHitbox :
	public AbstractHitbox
{
public:
	class Elevator *elevator;
	float offset_y;

	ElevatorHitbox(class Elevator *elevator, float offset_y = 0.0f);
	~ElevatorHitbox();

	float x1() const override;
	float y1() const override;
	float x2() const override;
	float y2() const override;
};

