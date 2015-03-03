#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "display.h"

Display* Display::instance_ = 0;

Display* Display::Instance() {

	if( instance_ == 0 ) {
		instance_ = new Display();
	}

	return instance_;
}

Display::Display() {
	// TODO : ctor
	quit_request_ = false;
	app_ = 0;
}

Display::~Display() {
	// TODO : dtor
}

void Display::Size(int width, int height) {
	width_ = width;
	height_ = height;
}

void Display::Init(int* argc, char* argv[]) {

	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_STENCIL | GLUT_DOUBLE);// | GLUT_DEPTH);
	glutInitWindowSize(width_, height_);
	glutCreateWindow("Lights & Shadows");

	GLenum glew_status = glewInit();
	if( glew_status != GLEW_OK ) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		exit(0);
	}

	glutDisplayFunc(Display::OnDisplay);
	glutKeyboardFunc(Display::OnKey);
	glutReshapeFunc(Display::OnReshape);
}

void Display::PreRender() {
	// TODO : pre-render steps
}

void Display::PostRender() {
	// TODO : post-render steps
	glutSwapBuffers();
	glutPostRedisplay();
}

void Display::Render() {

	if( ! quit_request_ ) {
		app_->render();
	}
	else {
		exit(0);
	}
}

void Display::Quit(bool quit) {

	quit_request_ = quit;
}

void Display::RegisterApplication(Application* app) {
	app_ = app;
}

void Display::Run() {

	glutMainLoop();
}

// BEGIN GLUT CALLBACKS
void Display::OnReshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
}

void Display::OnDisplay() {
	// TODO : this is glut display callback function.
	Display::Instance()->PreRender();

	Display::Instance()->Render();

	Display::Instance()->PostRender();
}

void Display::OnKey(unsigned char key, int x, int y) {
	// TODO : this is regular keyboard callback...
	x = x;
	y = y;

	switch( key ) {
		case 27:
		case 'q':
			Display::Instance()->Quit( true );

			break;

		default:
			;
	}
}
// END GLUT CALLBACKS