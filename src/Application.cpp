#include "Config.h"

#include "Application.h"

Application::Application() {

	width_ = Config::SCREEN_WIDTH;
	height_ = Config::SCREEN_HEIGHT;

	display_ = Display::Instance();
}

Application::~Application() {

}

void Application::render() {

	// Clear screen.
	display_->clear();

	std::vector< Light* >::iterator iLight;
	for (iLight = lights_.begin(); iLight != lights_.end(); ++iLight) {

		// Start rendering to stencil buffer.
		display_->setStencil();

		std::vector< Block* >::iterator iBlock;
		for (iBlock = blocks_.begin(); iBlock != blocks_.end(); ++iBlock) {

			std::vector< Edge* > edges;
			edges = (*iBlock)->getEdges();
			std::vector< Edge* >::iterator iEdge;
			for (iEdge = edges.begin(); iEdge != edges.end(); ++iEdge) {

				EdgeShadow* edge_shadow;
				edge_shadow = (*iEdge)->castShadow( *iLight );

				// TODO : display_draw_edge_shadow
				display_->drawEdgeShadow( edge_shadow );
			}
		}

		// End rendering to stencil buffer.
		display_->resetStencil();

		// Run shader program for given light.
		display_->runShader( *iLight );
	}

	// Draw all blocks over the scene.
	display_->drawBlocks( blocks_ );

	// Refresh display.
	display_->refresh();
}

int Application::randomInRange(int min, int max) {
	// TODO :
	return max-min;
}

void Application::setUpObjects() {

	// Random number of lights in a given range.
	int lightCount = randomInRange(Config::MIN_LIGHTS, Config::MAX_LIGHTS);

	// Create lights.
	for (int i = 1; i <= lightCount; i++) {

		Light* new_light = new Light();
		lights_.push_back( new_light );
	}

	// Random number of blocks in a given range.
	int blockCount = randomInRange(Config::MIN_BLOCKS, Config::MAX_BLOCKS);

	// Create blocks.
	for (int i = 1; i <= blockCount; i++) {

		Block* new_block = new Block();
		blocks_.push_back( new_block );
	}
}

void Application::initialize() {

	// Open graphics window & mode, etc.
	display_->open();

	// Initialize fragment shader.
	display_->initShader();

	// Complete graphics initialization.
	display_->initialize();
}

void Application::cleanup() {

	// Delete and free shader program.
	display_->deleteShader();

	// Delete and destroy display.
	display_->destroy();
}

bool Application::isCloseRequested() {

	// Return quit request from display object.
	return display_->quitRequest();
}


