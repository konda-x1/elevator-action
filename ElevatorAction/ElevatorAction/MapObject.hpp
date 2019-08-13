#pragma once
class MapObject
{
public:
	int x;
	MapObject(int x);
	~MapObject();
	virtual void process(float delta) = 0;
	virtual void render(float delta) = 0;
};

