#pragma once
#include <vector>
#include <set>
#include <utility>
#include "LevelObject.hpp"
#include "SingleFloorLevelObject.hpp"
#include "Elevator.hpp"
class Level
{
	std::vector<LevelObject*> objects = std::vector<LevelObject*>();
	std::set<std::pair<int, int>> occupied = std::set<std::pair<int, int>>();
	std::set<std::pair<int, int>> elevator_occupied = std::set<std::pair<int, int>>();
	bool built = false;

	int remaining_free();
	void generate_missing();
	void generate_missing_doors();
	void insert_document_doors();
public:
	int width;
	int height;
	int document_doors;

	Level(int width, int height, int document_doors);
	~Level();

	int size();
	void add_elevator(Elevator *e);
	void add_xy(SingleFloorLevelObject *sflo);
	void process(float delta);
	void render(float delta);
	void build();
};

