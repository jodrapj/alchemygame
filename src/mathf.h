#pragma once
#include <math.h>

#include <iostream>

// Clamps value between min and max if it exceeds them
#define clamp(value, min, max) fmax(fmin(value, max), min)
//float clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }

struct Vector2f {
	Vector2f() : x(0.0f), y(0.0f) {}
	Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}
	float x, y;
	void print() { std::cout << x << ", " << y << std::endl; }
};