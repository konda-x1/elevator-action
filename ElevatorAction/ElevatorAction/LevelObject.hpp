#pragma once
#include "AbstractHitbox.hpp"
#include <vector>
class LevelObject
{
public:
	int x;
	std::vector<AbstractHitbox *> hitboxes = std::vector<AbstractHitbox *>();

	LevelObject(int x);
	~LevelObject();
	virtual void process(float delta) = 0;
	virtual void render(float delta) = 0;
};

