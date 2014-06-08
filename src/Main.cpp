#include "Display.h"
#include "Application.h"

int main(int argc, char* argv[]) {

    Display* display = Display::Instance();
	Application* app = new Application();	

    app->initialize();

    // Open graphics window & mode, etc.
    display->open(&argc, argv);

    display->registerApplication(app);

    display->run();

	delete app;

    display->destroy();    
}