#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f {

public:
	Vector2f();
	Vector2f(float x, float y);
	~Vector2f();
	
	void set(float x, float y);
    Vector2f operator-(const Vector2f& v) const;
    Vector2f operator+(const Vector2f& v) const;
    float operator*(const Vector2f& v) const;
    Vector2f operator*(float a) const;
    Vector2f normal();

private:
	float x_;
	float y_;
};

#endif