#pragma once
#include "Door.hpp"
class EnemyDoor :
	public Door
{
public:
	EnemyDoor(int x, int y);
	~EnemyDoor();

	void process(float delta) override;
};

