#ifndef EDGESHADOW_H
#define EDGESHADOW_H

#include <vector>

#include "Vector2f.h"

class EdgeShadow {

public:
	EdgeShadow();
	~EdgeShadow();

    void addVertex(Vector2f vertex);
    void render();

private:
    std::vector< Vector2f > vertices_;
};

#endif