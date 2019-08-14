#pragma once
#include "AbstractHitbox.hpp"

class Hitbox : public AbstractHitbox
{
	int _x1, _y1;
	int _x2, _y2;
public:
	Hitbox(int x1, int y1, int x2, int y2);
	~Hitbox();

	float x1() const override;
	float y1() const override;
	float x2() const override;
	float y2() const override;
	virtual void set_x1(float value);
	virtual void set_y1(float value);
	virtual void set_x2(float value);
	virtual void set_y2(float value);
};

