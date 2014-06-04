#include "Light.h"

Light::Light() : location_(0.0, 0.0) {
	// TODO : ctor

}

Light::~Light() {
	// TODO : dtor
}

void Light::randomColor() {
	// TODO : set random color.
	color_ = -1;
}

void Light::randomLocation() {
	// TODO : set random location.
	location_.set(1.2, 3.4);
}

