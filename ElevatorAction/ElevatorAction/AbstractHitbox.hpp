#pragma once
class AbstractHitbox
{
public:
	AbstractHitbox(bool solid);
	~AbstractHitbox();
	bool solid;

	virtual float x1() const = 0;
	virtual float y1() const = 0;
	virtual float x2() const = 0;
	virtual float y2() const = 0;
	float left();
	float right();
	float top();
	float bottom();
	bool collides(AbstractHitbox *h);
	virtual void render(float delta, float r, float g, float b);
};

