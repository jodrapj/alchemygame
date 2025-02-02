#pragma once
#include <math.h>

// Clamps value between min and max if it exceeds them
float clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }