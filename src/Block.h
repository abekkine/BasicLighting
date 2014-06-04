#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "Edge.h"

class Block {

public:
	Block();
	~Block();

	void location(int x, int y);
	void size(int width, int height);
	std::vector< Edge* >& getEdges();

private:
	void deleteEdges();
	void updateEdges();
	void setEdges();
	void randomLocation();	

private:
	std::vector< Edge* > edges_;
	int x_;
	int y_;
	int width_;
	int height_;
};

#endif