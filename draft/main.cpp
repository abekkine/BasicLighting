#include <stdio.h>

#include "display.h"
#include "application.h"

int main(int argc, char* argv[]) {

	int width = 800;
	int height = 600;

	Display* display = Display::Instance();
	Application* app = new Application();

	display->Size(width, height);
	display->Init(&argc, argv);

	app->size(width, height);
	app->setupObjects();
	app->initialize();

	display->RegisterApplication( app );

	display->Run();

	app->cleanup();
}