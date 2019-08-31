#pragma once
#include "AbstractHitbox.hpp"
#include "Elevator.hpp"
class Elevator;
class ElevatorDeathbox :
	public AbstractHitbox
{
public:
	Elevator *elevator;

	ElevatorDeathbox(Elevator *elevator);
	~ElevatorDeathbox();

	float x1() const override;
	float y1() const override;
	float x2() const override;
	float y2() const override;
};

