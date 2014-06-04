#ifndef LIGHT_H
#define LIGHT_H

#include "Vector2f.h"
#include "Color.h"

class Light {

public:
	Light();
	~Light();

private:
	void randomColor();
	void randomLocation();

private:
	// Location
	Vector2f location_;
	// RGB Color
	Color color_;
};

#endif
