#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "vector2f.h"

class Block {
	
public:
	Block(int x, int y, int w, int h);
	~Block();
	std::vector< Vector2f* > GetVertices();

private:
	int x_;
	int y_;
	int width_;
	int height_;
	std::vector< Vector2f* > vertices_;
};

#endif