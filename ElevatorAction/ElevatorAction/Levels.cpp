#include "Levels.hpp"
#include "Level.hpp"
#include "Elevator.hpp"
#include "ExtraLife.hpp"


Levels::Levels()
{
}


Levels::~Levels()
{
}

Level * Levels::level1()
{
	Level *level = new Level(5, 3, 1);
	level->add_elevator(new Elevator(4, 1, 3, false));
	level->add_xy(new ExtraLife(1, 2));
	level->build();
	return level;
}

Level * Levels::level2()
{
	return nullptr;
}

Level * Levels::level3()
{
	return nullptr;
}
