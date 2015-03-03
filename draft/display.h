#ifndef DISPLAY_H
#define DISPLAY_H

#include "application.h"

class Display {

private:
	static Display* instance_;
	Display();

public:
	static Display* Instance();
	~Display();

	void Size(int width, int height);
	void Init(int* argc, char* argv[]);
	void PreRender();
	void PostRender();
	void Quit( bool quit );
	void RegisterApplication( Application* app );
	void Run();
	void Render();

	// Begin GLUT callback functions.
	static void OnDisplay();
	static void OnKey(unsigned char key, int x, int y);
	static void OnReshape(int width, int height);
	// End GLUT callback functions.	

private:
	Application* app_;
	bool quit_request_;
	int width_;
	int height_;
};

#endif