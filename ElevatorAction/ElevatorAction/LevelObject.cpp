#include "LevelObject.hpp"



LevelObject::LevelObject(int x) : x(x)
{
}


LevelObject::~LevelObject()
{
	for (AbstractHitbox *ah : this->hitboxes) {
		delete ah;
	}
}
