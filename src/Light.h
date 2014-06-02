#ifndef LIGHT_H
#define LIGHT_H

class Light {

public:
	Light();
	~Light();

	void randomColor();
	void randomLocation();

private:
	// Location
	int location_;
	// RGB Color
	int color_;
};

#endif
