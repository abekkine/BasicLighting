#include "Color.h"

Color::Color() {
	// Set to white, initially.
	set(1.0, 1.0, 1.0);
}

Color::Color(float r, float g, float b) {
	// Set to given color on construction
	set(r, g, b);
}

Color::~Color() {
	// TODO : dtor
}

void Color::set(float r, float g, float b) {
	red_ = r;
	green_ = g;
	blue_ = b;
}