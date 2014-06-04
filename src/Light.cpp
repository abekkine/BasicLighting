#include "Util.h"
#include "Config.h"

#include "Light.h"

Light::Light() {
	// TODO : ctor
}

Light::~Light() {
	// TODO : dtor
}

void Light::randomColor() {

	// Set random color.
	float r = Util::randomInRange(0.0, Config::COLOR_MAX);
	float g = Util::randomInRange(0.0, Config::COLOR_MAX);
	float b = Util::randomInRange(0.0, Config::COLOR_MAX);
	color_.set(r, g, b);
}

void Light::randomLocation() {

	// Set random location.
	float x = Util::randomInRange(0.0, Config::SCREEN_WIDTH);
	float y = Util::randomInRange(0.0, Config::SCREEN_HEIGHT);

	location_.set(x, y);
}

