#ifndef EDGE_H
#define EDGE_H

#include "Vector2f.h"
#include "Light.h"
#include "EdgeShadow.h"

class Edge {

public:
	Edge();
    Edge(Vector2f b, Vector2f e);
	~Edge();

	void begin(Vector2f b);
	void end(Vector2f e);
	EdgeShadow* castShadow( Light* light );

private:
	Vector2f begin_;
	Vector2f end_;
};

#endif