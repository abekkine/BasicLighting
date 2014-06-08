#include <stdio.h>

#include "Util.h"
#include "Config.h"
#include "Display.h"

#include "Application.h"

Application::Application() {

	width_ = Config::SCREEN_WIDTH;
	height_ = Config::SCREEN_HEIGHT;
}

Application::~Application() {

	// Destroy lights.
	std::vector< Light* >::iterator iLight;
	for(iLight = lights_.begin(); iLight != lights_.end(); ++iLight) {
		delete (*iLight);
	}

	std::vector< Block* >::iterator iBlock;
	for(iBlock = blocks_.begin(); iBlock != blocks_.end(); ++iBlock) {
		delete (*iBlock);
	}
}

void Application::render() {

	std::vector< Light* >::iterator iLight;
	for (iLight = lights_.begin(); iLight != lights_.end(); ++iLight) {

		// Start rendering to stencil buffer.
		Display::Instance()->setStencil();

		std::vector< Block* >::iterator iBlock;
		for (iBlock = blocks_.begin(); iBlock != blocks_.end(); ++iBlock) {

			std::vector< Edge* > edges;
			edges = (*iBlock)->getEdges();
			std::vector< Edge* >::iterator iEdge;
			for (iEdge = edges.begin(); iEdge != edges.end(); ++iEdge) {

				EdgeShadow* edge_shadow;
				edge_shadow = (*iEdge)->castShadow( *iLight );

				// Display edge shadow.
				Display::Instance()->drawEdgeShadow( edge_shadow );

				delete edge_shadow;
			}
		}

		// End rendering to stencil buffer.
		Display::Instance()->resetStencil();

		// Run shader program for given light.
		Display::Instance()->runShader( *iLight );
	}

	// Draw all blocks over the scene.
	Display::Instance()->drawBlocks( blocks_ );
}

void Application::setUpObjects() {

	// Random number of lights in a given range.
	int lightCount = Util::randomInRange(Config::MIN_LIGHTS, Config::MAX_LIGHTS);

	// Create lights.
	for (int i = 1; i <= lightCount; i++) {

		Light* new_light = new Light();
		lights_.push_back( new_light );
	}

	// Random number of blocks in a given range.
	int blockCount = Util::randomInRange(Config::MIN_BLOCKS, Config::MAX_BLOCKS);

	// Create blocks.
	for (int i = 1; i <= blockCount; i++) {

		Block* new_block = new Block();
		blocks_.push_back( new_block );
	}
}

void Application::initialize() {

	setUpObjects();
}




