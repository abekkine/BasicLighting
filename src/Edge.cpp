#include "Edge.h"

Edge::Edge() {
	// TODO : ctor
}

Edge::~Edge() {
	// TODO : dtor
}

EdgeShadow* Edge::castShadow( Light* light ) {

	// TODO : implement
	light = light;
	return new EdgeShadow();
}