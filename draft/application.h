#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>

#include "application.h"
#include "light.h"
#include "block.h"

class Application {

public:
	// public stuff.
	Application();
	~Application();
	void setupObjects();
	void initialize();
	void render();
	void cleanup();
	void size(int w, int h);
	void drawBlocks();
	void drawLights(Light* light);
	void drawBlockShadows(Light* light);
	void drawAllShadows();

private:
	// private stuff.
	int width_;
	int height_;
	// TODO : define Light class
	std::vector< Light* > lights;
	// TODO : define Block class
	std::vector< Block* > blocks;
	int fragmentShader_;
	int shaderProgram_;
};


#endif