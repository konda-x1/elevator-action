#include <utility>
#include <exception>
#include <iostream>
#include "Level.hpp"
#include "util.hpp"
#include "DocumentDoor.hpp"
#include "EnemyDoor.hpp"
#include "Platform.hpp"

#include "glut/glut.h"


int Level::remaining_free()
{
	return this->size() - this->occupied.size();
}

void Level::generate_missing()
{
	this->generate_missing_doors();
	this->generate_missing_platforms();
}

void Level::generate_roof()
{
	for (int x = 1; x <= this->width; x++)
		this->add_platform(x, this->height + 1);
}

void Level::generate_missing_doors()
{
	this->insert_document_doors();
	// Fill up the rest of free space with enemy doors
	bool b = false; // Break condition
	for (int y = 1; y <= this->height && !b; y++) {
		for (int x = 1; x <= this->width && !b; x++) {
			if (this->occupied.count(std::make_pair(x, y)) == 0) { // Free position
				this->add_xy(new EnemyDoor(x, y));
			}
			b = this->remaining_free() <= 0;
		}
	}
}

void Level::generate_missing_platforms()
{
	for (int y = 1; y <= this->height; y++) {
		for (int x = 1; x <= this->width; x++) {
			std::pair<int, int> xy = std::make_pair(x, y);
			if (!this->platform_occupied.count(xy) && !this->elevator_occupied.count(xy)) { // Not occupied by either a platform or an elevator
				this->add_platform(x, y);
			}
		}
	}
}

void Level::insert_document_doors()
{
	int remaining_document = this->document_doors;
	while (this->remaining_free() > 0 && remaining_document > 0) {
		int posx, posy;
		do {	// Find a random free position in the level to insert document doors
			posx = randint(1, this->width);
			posy = randint(1, this->height);
		} while (this->occupied.count(std::make_pair(posx, posy)));
		this->add_xy(new DocumentDoor(posx, posy));
		--remaining_document;
		std::cout << "Added DocumentDoor." << std::endl;
	}
}

Level::Level(int width, int height, int document_doors): width(width), height(height), document_doors(document_doors)
{
}


Level::~Level()
{
	for (LevelObject *lo : this->objects)
		delete lo;
}

int Level::size()
{
	return this->width * this->height;
}

void Level::add_elevator(Elevator* e)
{
	for (int i = e->min_floor; i <= e->max_floor; i++) {
		auto xy = std::pair<int, int>(e->x, i);
		this->occupied.insert(xy);
		this->elevator_occupied.insert(xy);
	}
	this->objects.push_back(e);
}

void Level::add_platform(int x, int y)
{
	this->platform_occupied.insert(std::make_pair(x, y));
	this->objects.push_back(new Platform(x, y));
}

void Level::add_xy(SingleFloorLevelObject * sflo)
{
	this->occupied.insert(std::make_pair(sflo->x, sflo->y));
	this->objects.push_back(sflo);
}

void Level::process(float delta)
{
	for (LevelObject *object : this->objects)
		object->process(delta);
}

void Level::render(float delta)
{
	glLoadIdentity();
	glTranslatef(-1.0f, -1.0f, 0.0f);
	glScalef(2.0f / (float)this->width, 2.0f / (float)this->width, 1.0f);
	for (LevelObject *object : this->objects)
		object->render(delta);
}

void Level::build()
{
	if (this->built)
		throw std::exception("Level has already been built");
	this->generate_missing();
	this->generate_roof();
	//this->built = true;
}
