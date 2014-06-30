#include <GL/freeglut.h>

#include "EdgeShadow.h"

EdgeShadow::EdgeShadow() {
}

EdgeShadow::~EdgeShadow() {
}

void EdgeShadow::addVertex(Vector2f vertex) {

    vertices_.push_back( vertex );
}

void EdgeShadow::render() {

    std::vector< Vector2f >::iterator iVertice;

    glColor4f(1.0, 1.0, 1.0, 0.2);
    glBegin(GL_QUADS);
        for(iVertice=vertices_.begin(); iVertice!=vertices_.end(); ++iVertice) {
            glVertex2f( (*iVertice).X(), (*iVertice).Y() );
        }
    glEnd();
}