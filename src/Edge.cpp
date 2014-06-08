#include "Edge.h"

Edge::Edge(Vector2f b, Vector2f e) {
    
    begin( b );
    end( e );
}

Edge::~Edge() {
}

void Edge::begin( Vector2f b ) {

	begin_ = b;
}

void Edge::end( Vector2f e ) {

	end_ = e;
}

EdgeShadow* Edge::castShadow( Light* light ) {

	// Cast edge shadow from given light.
    EdgeShadow* shadow = 0;

    end_ - begin_;

    Vector2f edgeVector = end_ - begin_;
    Vector2f normal = edgeVector.normal();
    Vector2f lightToBegin = begin_ - light->location();

    if( normal * lightToBegin > 0 ) {
        Vector2f lightToEnd = end_ - light->location();
        // TODO : May need to extend more.
        Vector2f beginExtend = begin_ + lightToBegin * 5;
        Vector2f endExtend = end_ + lightToEnd * 5;

        shadow = new EdgeShadow();
        shadow->addVertex(begin_);
        shadow->addVertex(beginExtend);
        shadow->addVertex(endExtend);
        shadow->addVertex(end_);
    }

    return shadow;
}