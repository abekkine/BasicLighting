#include "Block.h"

Block::Block() {
	// TODO : ctor
}

Block::~Block() {
	// TODO : dtor
}

void Block::size(int width, int height) {

	width_ = width;
	height_ = height;
}

void Block::randomLocation() {

	// TODO : initialize with a random location within boundaries.
	x_ = -1;
	y_ = -1;
}

std::vector< Edge* >& Block::getEdges() {

	return edges_;
}
