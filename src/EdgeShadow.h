#ifndef EDGESHADOW_H
#define EDGESHADOW_H

#include <vector>

#include "Vector2f.h"

// TODO : Implement properly.
class EdgeShadow {

public:
	EdgeShadow();
	~EdgeShadow();

    void addVertex(Vector2f vertex);

private:
    std::vector< Vector2f > vertices_;
};

#endif