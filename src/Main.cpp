#include "Application.h"

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