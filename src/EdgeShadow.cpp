#include "EdgeShadow.h"

EdgeShadow::EdgeShadow() {
	// TODO : ctor
}

EdgeShadow::~EdgeShadow() {
}

void EdgeShadow::addVertex(Vector2f vertex) {

    vertices_.push_back( vertex );
}