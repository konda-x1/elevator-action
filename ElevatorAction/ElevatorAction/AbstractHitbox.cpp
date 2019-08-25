#include "AbstractHitbox.hpp"
#include <algorithm>


AbstractHitbox::AbstractHitbox()
{
}


AbstractHitbox::~AbstractHitbox()
{
}

float AbstractHitbox::left()
{
	return (float)std::min(this->x1(), this->x2());
}

float AbstractHitbox::right()
{
	return (float)std::max(this->x1(), this->x2());
}

float AbstractHitbox::top()
{
	return (float)std::max(this->y1(), this->y2());
}

float AbstractHitbox::bottom()
{
	return (float)std::min(this->y1(), this->y2());
}

bool AbstractHitbox::collides(AbstractHitbox *h)
{
	bool horizontal = this->left() >= h->left() && this->left() <= h->right() || this->right() >= h->left() && this->right() <= h->right();
	bool vertical = this->bottom() >= h->bottom() && this->bottom() <= h->top() || this->top() >= h->bottom() && this->top() <= h->top();
	return horizontal && vertical;
}
