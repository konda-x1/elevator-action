#pragma once
#include <utility>
int randint(int min_val, int max_val);
float to_x1(int x, int y, float width, float height);
float to_y1(int x, int y, float width, float height);
float to_x2(int x, int y, float width, float height);
float to_y2(int x, int y, float width, float height);
void v2normalize(float *x, float *y);
float v2len(float x, float y);
