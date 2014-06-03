#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

#include "EdgeShadow.h"
#include "Light.h"
#include "Block.h"
#include "Display.h"

class Application {

public:
	Application();
	~Application();

	void render();
	void setUpObjects();
	void initialize();
	void cleanup();
	bool isCloseRequested();
	int randomInRange(int min, int max);

private:

	Display* display_;
	int width_;
	int height_;
	std::vector< Light* > lights_;
	std::vector< Block* > blocks_;
};

#endif