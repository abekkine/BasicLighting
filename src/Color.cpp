#include "Color.h"

Color::Color() {
	// Set to white, initially.
	set(1.0, 1.0, 1.0);
}

Color::~Color() {
}

void Color::set(float r, float g, float b) {
	red_ = r;
	green_ = g;
	blue_ = b;
}