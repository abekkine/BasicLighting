#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f {
	// TODO : Implement...
public:
	Vector2f(float x, float y);
	~Vector2f();
	float X();
	float Y();
	Vector2f sub(Vector2f v);
	Vector2f add(Vector2f v);
	float dot(Vector2f v);
	Vector2f scale(float s);

private:
	float x_;
	float y_;

};

#endif