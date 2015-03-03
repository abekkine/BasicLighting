#include <stdio.h>

#include "light.h"

Light::Light(Vector2f* location, float red, float green, float blue) {

	location_ = location;
	red_ = red;
	green_ = green;
	blue_ = blue;

#ifdef DEBUG
	printf("Light(%.1f, %.1f, %.1f)\n", red_, green_, blue_);
#endif
}

Light::~Light() {
	// TODO : Dtor
}

float Light::Red() {
	return red_;
}

float Light::Green() {
	return green_;
}

float Light::Blue() {
	return blue_;
}

Vector2f* Light::Location() {

	return location_;
}
