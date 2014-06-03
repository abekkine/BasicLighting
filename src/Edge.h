#ifndef EDGE_H
#define EDGE_H

#include "Light.h"
#include "EdgeShadow.h"

// TODO : Implement properly.
class Edge {

public:
	Edge();
	~Edge();

	EdgeShadow* castShadow( Light* light );
};

#endif