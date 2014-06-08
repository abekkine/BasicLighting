#ifndef COLOR_H
#define COLOR_H

class Color {

public:
	Color();
	~Color();
	void set(float r, float g, float b);

private:
	float red_;
	float green_;
	float blue_;
};

#endif