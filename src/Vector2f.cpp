#include "Vector2f.h"

Vector2f::Vector2f() {

	// For constructions without parameter.
	set(0.0, 0.0);
}

Vector2f::Vector2f(float x, float y) {

	set(x, y);
}

Vector2f::~Vector2f() {
}

void Vector2f::set(float x, float y) {

	x_ = x;
	y_ = y;
}

Vector2f Vector2f::operator-(const Vector2f& v) const {
    return Vector2f(x_ - v.x_, y_ - v.y_);
}

Vector2f Vector2f::operator+(const Vector2f& v) const {
    return Vector2f(x_ + v.x_, y_ + v.y_);
}

Vector2f Vector2f::operator*(float a) const {
    return Vector2f(x_ * a, y_ * a);
}

float Vector2f::operator*(const Vector2f& v) const {
    return (x_ * v.x_ + y_ * v.y_);
}

Vector2f Vector2f::normal() {

    return Vector2f(y_, -x_);
}