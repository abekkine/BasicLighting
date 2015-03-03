#include <stdio.h>

#include "vector2f.h"

Vector2f::Vector2f(float x, float y) {

	x_ = x;
	y_ = y;
#ifdef DEBUG
	printf("Vector2f(%.1f, %.1f)\n", x_, y_);
#endif
}

Vector2f::~Vector2f() {

}

float Vector2f::X() {
	return x_;
}

float Vector2f::Y() {
	return y_;
}

Vector2f Vector2f::add(Vector2f v) {

	return Vector2f(x_ + v.X(), y_ + v.Y());
}

Vector2f Vector2f::sub(Vector2f v) {

	return Vector2f(x_ - v.X(), y_ - v.Y());
}

float Vector2f::dot(Vector2f v) {

	return x_*v.X() + y_*v.Y();
}

Vector2f Vector2f::scale(float s) {

	return Vector2f(s*x_, s*y_);
}