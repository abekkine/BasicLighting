#include "Config.h"

#include "Application.h"

Application::Application() {

	width_ = Config::SCREEN_WIDTH;
	height_ = Config::SCREEN_HEIGHT;
}

Application::~Application() {

}

EdgeShadow* Application::castEdgeShadow( Light* light ) {

	light = light;

	return new EdgeShadow();
}

void Application::render() {

	// TODO : display_clear	

	std::vector< Light* >::iterator iLight;
	for (iLight = lights_.begin(); iLight != lights_.end(); ++iLight) {

		// TODO : display_set_stencil

		std::vector< Block* >::iterator iBlock;
		for (iBlock = blocks_.begin(); iBlock != blocks_.end(); ++iBlock) {

			std::vector< Edge* > edges;
			edges = (*iBlock)->getEdges();
			std::vector< Edge* >::iterator iEdge;
			for (iEdge = edges.begin(); iEdge != edges.end(); ++iEdge) {

				EdgeShadow* edge_shadow = 0;
				edge_shadow = castEdgeShadow( *iLight );

				edge_shadow = edge_shadow;

				// TODO : display_draw_edge_shadow
			}
		}

		// TODO : display_reset_stencil

		// TODO : display_execute_shader
	}

	// TODO : display_draw_blocks

	// TODO : display_refresh
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
		new_light->randomColor();
		new_light->randomLocation();

		lights_.push_back( new_light );
	}

	// Random number of blocks in a given range.
	int blockCount = randomInRange(Config::MIN_BLOCKS, Config::MAX_BLOCKS);

	// Create blocks.
	for (int i = 1; i <= blockCount; i++) {

		Block* new_block = new Block();
		new_block->size(50, 50);
		new_block->randomLocation();

		blocks_.push_back( new_block );
	}
}

void Application::initialize() {

	// TODO : display_open

	// TODO : display_init_shader

	// TODO : display_initialize
}

void Application::cleanup() {

	// TODO : display_delete_shader

	// TODO : display_destroy
}

bool Application::isCloseRequested() {

	// TODO : display_quit_request
	return true;
}

int main() {

	Application* app = new Application();	

	app->setUpObjects();
	app->initialize();

	// Note: since we have no display yet;
	while (!app->isCloseRequested()) {
		app->render();
	}

	app->cleanup();

	delete app;
}

