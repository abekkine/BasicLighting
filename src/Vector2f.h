#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f {

public:
	Vector2f(float x, float y);
	~Vector2f();
	void set(float x, float y);

private:
	float x_;
	float y_;
};

#endif