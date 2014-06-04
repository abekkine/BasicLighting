#ifndef LIGHT_H
#define LIGHT_H

#include "Vector2f.h"

class Light {

public:
	Light();
	~Light();

	void randomColor();
	void randomLocation();

private:
	// Location
	Vector2f location_;
	// RGB Color
	// TODO : invalid color type.
	int color_;
};

#endif
