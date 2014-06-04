#include "Vector2f.h"

Vector2f::Vector2f(float x, float y) {

	set(x, y);
}

Vector2f::~Vector2f() {
	// TODO : ctor
}

void Vector2f::set(float x, float y) {

	x_ = x;
	y_ = y;
}