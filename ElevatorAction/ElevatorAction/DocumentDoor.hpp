#pragma once
#include "Door.hpp"
class DocumentDoor :
	public Door
{
public:
	DocumentDoor(int x, int y);
	~DocumentDoor();

	void process(float delta) override;
	void render(float delta) override;
};

