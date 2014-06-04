#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

#include "Block.h"
#include "Light.h"
#include "EdgeShadow.h"

class Display {

private:
	static Display* instance_;
	Display();

public:
	static Display* Instance();
	~Display();
	static void destroy();
	void resetInstance();

	void clear();
	void setStencil();
	void resetStencil();
	void drawEdgeShadow( EdgeShadow* edge_shadow );
	void runShader( Light* light );
	void drawBlocks( std::vector< Block* >& blocks );
	void refresh();
	void open();
	void initShader();
	void initialize();
	void deleteShader();

	bool quitRequest();
};

#endif