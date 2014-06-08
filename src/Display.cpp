#include "Display.h"

Display* Display::instance_ = 0;

Display* Display::Instance() {

	if( instance_ == 0 ) {
		instance_ = new Display();
	}

	return instance_;
}

void Display::resetInstance() {
	instance_ = 0;
}

void Display::destroy() {

	Display* instance = Display::Instance();
	instance->resetInstance();
	delete instance;
}

Display::Display() {
	// TODO : ctor
}

Display::~Display() {
}

void Display::clear() {
	// TODO : clear screen.
}

void Display::setStencil() {
	// TODO : set stencil.
}

void Display::resetStencil() {
	// TODO : reset stencil.
}

void Display::drawEdgeShadow( EdgeShadow* edge_shadow ) {
	// TODO : render shadow edge
	edge_shadow = edge_shadow;
}

void Display::runShader( Light* light ) {
	// TODO : run shader program.
	light = light;
}

void Display::drawBlocks( std::vector< Block* >& blocks ) {
	// TODO : render blocks.
	blocks.clear();
}

void Display::refresh() {
	// TODO : refresh/update display
}

void Display::open() {
	// TODO : open window, initiate display mode.
}

void Display::initShader() {
	// TODO : initialize shader program.
}

void Display::initialize() {
	// TODO : complete display initialization.
}

void Display::deleteShader() {
	// TODO : delete shader program.
}

bool Display::quitRequest() { 
	 // TODO return quit request.

	static int count=1000;
	bool quit = false;

	count--;
	if (count < 0) {
		quit = true;
	}

	return quit;
}
