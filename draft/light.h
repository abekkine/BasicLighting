#ifndef LIGHT_H
#define LIGHT_H

#include "vector2f.h"

class Light {
	// TODO : implement...
public:
	Light(Vector2f* location, float r, float g, float b);
	~Light();

	float Red();
	float Green();
	float Blue();
	Vector2f* Location();

private:
	Vector2f* location_;
	float red_;
	float green_;
	float blue_;
};

#endif