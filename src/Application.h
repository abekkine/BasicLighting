#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

namespace Config {

	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT = 600;
	int MIN_LIGHTS = 5;
	int MAX_LIGHTS = 10;
	int MIN_BLOCKS = 5;
	int MAX_BLOCKS = 10;
}

#include "Light.h"
#include "Block.h"

class Application {

public:
	Application();
	~Application();

	void render();
	void setUpObjects();
	void initialize();
	void cleanup();
	bool isCloseRequested();
	EdgeShadow* castEdgeShadow( Light* light );
	int randomInRange(int min, int max);

private:

	int width_;
	int height_;
	std::vector< Light* > lights_;
	std::vector< Block* > blocks_;
};

#endif