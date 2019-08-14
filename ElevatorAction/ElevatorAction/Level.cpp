#include "Level.hpp"
#include <utility>


Level::Level(int width, int height): width(width), height(height)
{
}


Level::~Level()
{
}

void Level::add_elevator(Elevator* e)
{
	for (int i = e->min_floor; i <= e->max_floor; i++)
		this->elevator_occupied.insert(std::pair<int, int>(e->x, i));
	this->objects.push_back(e);
}

void Level::process(float delta)
{
	for (LevelObject *object : this->objects)
		object->process(delta);
}

void Level::render(float delta)
{
	for (LevelObject *object : this->objects)
		object->render(delta);
}
