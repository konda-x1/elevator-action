#include "DocumentDoor.hpp"



DocumentDoor::DocumentDoor(int x, int y) : Door(x, y, 0.8f, 0.0f, 0.0f)
{
}


DocumentDoor::~DocumentDoor()
{
}

void DocumentDoor::process(float delta)
{
	Door::process(delta); // Process elapsed time if door is open
}
