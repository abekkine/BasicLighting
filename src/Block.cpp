#include "Util.h"
#include "Config.h"

#include "Block.h"

Block::Block() {

	// Default constructor creates a block of size 50
	// with a random location.
	size(Config::BLOCK_SIZE, Config::BLOCK_SIZE);
	randomLocation();

	// Calculate edges accordingly.
	setEdges();
}

Block::~Block() {

	deleteEdges();
}

void Block::deleteEdges() {

	// TODO : Delete edges.
}

void Block::setEdges() {

	// TODO : Set/Create edges.
}

void Block::updateEdges() {

	// TODO : Update edges.
}

void Block::location(int x, int y) {

	x_ = x;
	y_ = y;

	// Update edges according to location change.
	updateEdges();
}

void Block::size(int width, int height) {

	width_ = width;
	height_ = height;

	// Update edges according to size change.
	updateEdges();
}

void Block::randomLocation() {

	// Initialize with a random location within boundaries.
	int margin = 10;

	x_ = Util::randomInRange(
		margin,
		Config::SCREEN_WIDTH - width_ - margin
	);

	y_ = Util::randomInRange(
		margin,
		Config::SCREEN_HEIGHT - height_ - margin 
	);
}

std::vector< Edge* >& Block::getEdges() {

	return edges_;
}
