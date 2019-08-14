#pragma once
#include <vector>
#include <set>
#include <utility>
#include "LevelObject.hpp"
#include "Elevator.hpp"
class Level
{
	std::vector<LevelObject*> objects = std::vector<LevelObject*>();
	std::set<std::pair<int, int>> elevator_occupied = std::set<std::pair<int, int>>();
public:
	int width;
	int height;

	Level(int width, int height);
	~Level();

	void add_elevator(Elevator *e);
	void process(float delta);
	void render(float delta);
};

