#include <cstdlib>
#include "util.hpp"

int randint(int min_val, int max_val)
{
	return rand() % (max_val - min_val + 1) + min_val;
}

float to_x1(int x, int y, float width, float height)
{
	return (float)x - 0.5f - width / 2.0f;
}

float to_y1(int x, int y, float width, float height)
{
	return (float)y - 1.0f + height;
}

float to_x2(int x, int y, float width, float height)
{
	return (float)x - 0.5f + width / 2.0f;
}

float to_y2(int x, int y, float width, float height)
{
	return (float)y - 1.0f;
}
