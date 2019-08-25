#pragma once
class AbstractHitbox
{
public:
	AbstractHitbox();
	~AbstractHitbox();

	virtual float x1() const = 0;
	virtual float y1() const = 0;
	virtual float x2() const = 0;
	virtual float y2() const = 0;
	float left();
	float right();
	float top();
	float bottom();
	bool collides(AbstractHitbox *h);
};

