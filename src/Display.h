#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

#include "Block.h"
#include "Light.h"
#include "EdgeShadow.h"
#include "Application.h"

class Display {

private:
	static Display* instance_;
	Display();
	void eventLocation(int x, int y);
	void render();
	void initShader();
	void initialize();
	void deleteShader();
	void clear();
	void refresh();

public:
	static Display* Instance();
	~Display();
	static void destroy();
	void resetInstance();
	void registerApplication(Application* app);

	void run();
	void setStencil();
	void resetStencil();
	void drawEdgeShadow( EdgeShadow* edge_shadow );
	void runShader( Light* light );
	void drawBlocks( std::vector< Block* >& blocks );
	void open(int* argc, char* argv[]);

public:
	// GLUT Callback Functions.
	static void displayNone();
	static void displayCallback();
	static void keyCallback(unsigned char key, int x, int y);
	static void reshapeCallback(int width, int height);

private:
	Application* app_;
	bool quit_;
	int event_x_;
	int event_y_;
};

#endif