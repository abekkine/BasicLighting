#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Config.h"

#include "Shader.h"

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

	quit_ = false;
	event_x_ = 0;
	event_y_ = 0;
}

Display::~Display() {

	// Delete and free shader program.
	deleteShader();	
}

void Display::registerApplication(Application* app) {
	app_ = app;
}

void Display::run() {

	// Display loop.
	glutMainLoop();
}

void Display::clear() {

	// Clear screen.
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::setStencil() {
	// TODO : set stencil.
}

void Display::resetStencil() {
	// TODO : reset stencil.
}

void Display::drawEdgeShadow( EdgeShadow* edge_shadow ) {
	// TODO : render shadow edge
	if( edge_shadow != 0 ) {
		edge_shadow->render();
	}
	else {
		printf("edge_shadow is 0 (zero)\n");
	}
}

void Display::runShader( Light* light ) {
	// TODO : run shader program.
	glColor3f( 1.0, 1.0, 1.0 );
	glPointSize(2.0);
	glBegin(GL_POINTS);
		glVertex2f( light->location().X(), light->location().Y() );
	glEnd();
}

void Display::drawBlocks( std::vector< Block* >& blocks ) {
	// TODO : render blocks.
	std::vector< Block* >::iterator iBlock;

	for(iBlock=blocks.begin(); iBlock!=blocks.end(); ++iBlock) {
		(*iBlock)->render();
	}
}

void Display::refresh() {

	// Refresh/update display
	glutSwapBuffers();
	glutPostRedisplay();	
}

void Display::open(int* argc, char* argv[]) {

	// Open window, initiate display mode.
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
	glutCreateWindow("Lights & Shadows");

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	GLenum glew_status = glewInit();
	if( glew_status != GLEW_OK ) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		exit(0);
	}

    // Initialize fragment shader.
	initShader();

    // Complete graphics initialization.
	initialize();
}

void Display::initShader() {
	// TODO : initialize shader program.
}

void Display::initialize() {

	// Complete display initialization.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);

	// DEBUG
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// ENDDEBUG

	glutDisplayFunc(Display::displayCallback);
	glutKeyboardFunc(Display::keyCallback);
	glutReshapeFunc(Display::reshapeCallback);

	glClearColor(0.2, 0.2,  0.2, 0.0);
}

void Display::deleteShader() {
	// TODO : delete shader program.
}

void Display::eventLocation(int x, int y) {

	event_x_ = x;
	event_y_ = y;
}

void Display::render() {

	// Clear screen.
	clear();

	app_->render();

	// Refresh display.
	refresh();	
}

void Display::displayNone() {
}

void Display::displayCallback() {

	// Render job.
	Display::Instance()->render();
}

void Display::keyCallback(unsigned char key, int x, int y) {

	Display::Instance()->eventLocation(x, y);

	switch( key ) {
		case 27:
		case 'q':
			glutDisplayFunc(displayNone);
			glutLeaveMainLoop();
			break;

		default:
			;
	}
}

void Display::reshapeCallback(int width, int height) {

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
}