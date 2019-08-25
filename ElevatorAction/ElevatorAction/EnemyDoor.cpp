#include "EnemyDoor.hpp"



EnemyDoor::EnemyDoor(int x, int y) : Door(x, y, 0.0f, 0.0f, 0.8f)
{
}


EnemyDoor::~EnemyDoor()
{
}

void EnemyDoor::process(float delta)
{
	Door::process(delta); // Process elapsed time if door is open
}
