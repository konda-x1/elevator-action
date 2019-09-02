#include <cstdlib>
#include <cmath>
#include <assert.h>
#include <stdexcept>
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

void v2normalize(float *x, float *y)
{
	float length = v2len(*x, *y);
	assert(length >= 0.0f);
	if (length > 0.0f) {
		*x /= length;
		*y /= length;
	}
}

void v2normalize(std::pair<float, float>* xy)
{
	v2normalize(&xy->first, &xy->second);
}

float v2len(float x, float y)
{
	return sqrtf(x*x + y*y);
}

float v2len(std::pair<float, float> xy)
{
	return v2len(xy.first, xy.second);
}

float fsgn(float x)
{
	if (x > 0.0f)
		return 1.0f;
	else if (x < 0.0f)
		return -1.0f;
	else
		return 0.0f;
}

float fsgn2(float x)
{
	float sgn = fsgn(x);
	if (sgn == 0.0f)
		return 1.0f;
	else
		return sgn;
}

int fcmp(float x, float y, float epsillon)
{
	if (fabs(x - y) < epsillon)
		return 0;
	else if (x > y) {
		return 1;
	}
	else if (x < y) {
		return -1;
	}
	else {
		throw std::exception("Impossible case");
	}
}

bool feq(float x, float y, float epsillon)
{
	return fcmp(x, y, epsillon) == 0;
}

bool fle(float x, float y, float epsillon)
{
	return fcmp(x, y, epsillon) <= 0;
}

bool fge(float x, float y, float epsillon)
{
	return fcmp(x, y, epsillon) >= 0;
}

bool flt(float x, float y, float epsillon)
{
	return fcmp(x, y, epsillon) < 0;
}

bool fgt(float x, float y, float epsillon)
{
	return fcmp(x, y, epsillon) > 0;
}
