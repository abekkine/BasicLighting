#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "Edge.h"

class Block {

public:
	Block();
	~Block();

	void size(int width, int height);
	void randomLocation();
	std::vector< Edge* >& getEdges();

private:
	std::vector< Edge* > edges_;
	int x_;
	int y_;
	int width_;
	int height_;
};

#endif