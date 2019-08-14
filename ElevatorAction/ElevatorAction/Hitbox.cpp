#include "Hitbox.hpp"


Hitbox::Hitbox(int x1, int y1, int x2, int y2)
{
	this->set_x1(x1);
	this->set_y1(y1);
	this->set_x2(x2);
	this->set_y2(y2);
}

Hitbox::~Hitbox()
{
}

float Hitbox::x1() const
{
	return this->_x1;
}

float Hitbox::y1() const
{
	return this->_y1;
}

float Hitbox::x2() const
{
	return this->_x2;
}

float Hitbox::y2() const
{
	return this->_y2;
}

void Hitbox::set_x1(float value)
{
	this->_x1 = value;
}

void Hitbox::set_y1(float value)
{
	this->_y1 = value;
}

void Hitbox::set_x2(float value)
{
	this->_x2 = value;
}

void Hitbox::set_y2(float value)
{
	this->_y2 = value;
}

