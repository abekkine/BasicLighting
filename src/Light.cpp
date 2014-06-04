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
	// TODO : set random color.
	color_.set(1.2, 3.4, 5.6);
}

void Light::randomLocation() {

	float x = Util::randomInRange(0.0, Config::SCREEN_WIDTH);
	float y = Util::randomInRange(0.0, Config::SCREEN_HEIGHT);

	location_.set(x, y);
}

