#pragma once
class LevelObject
{
public:
	int x;
	LevelObject(int x);
	~LevelObject();
	virtual void process(float delta) = 0;
	virtual void render(float delta) = 0;
};

