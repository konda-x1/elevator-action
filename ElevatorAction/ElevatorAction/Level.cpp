#include "Level.hpp"
#include <utility>
#include <exception>


Level::Level(int width, int height): width(width), height(height)
{
}


Level::~Level()
{
	for (LevelObject *lo : this->objects)
		delete lo;
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

void Level::build()
{
	if (this->built)
		throw std::exception("Level has already been built");
	// TODO: Generate missing map objects
	this->built = true;
}
