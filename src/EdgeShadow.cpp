#include "EdgeShadow.h"

EdgeShadow::EdgeShadow() {
}

EdgeShadow::~EdgeShadow() {
}

void EdgeShadow::addVertex(Vector2f vertex) {

    vertices_.push_back( vertex );
}