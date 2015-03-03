#include <stdio.h>

#include <vector>

#include "block.h"

Block::Block(int x, int y, int w, int h) {
	x_ = x;
	y_ = y;
	width_ = w;
	height_ = h;

	vertices_.push_back(new Vector2f(x_, y_));
	vertices_.push_back(new Vector2f(x_+width_, y_));
	vertices_.push_back(new Vector2f(x_+width_, y_+height_));
	vertices_.push_back(new Vector2f(x_, y+height_));

#ifdef DEBUG
	printf("Block(%d, %d, %d, %d)\n", x_, y_, width_, height_);
#endif
}

Block::~Block() {
	// TODO : dtor.
}

std::vector< Vector2f* > Block::GetVertices() {

	return vertices_;
}
