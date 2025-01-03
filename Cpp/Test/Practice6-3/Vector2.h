#pragma once

#include <iostream>

class Vector2
{
public:
	Vector2(float x, float y);
	
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator/(const Vector2& other);
	Vector2 operator+=(const Vector2& other);

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& other);

private:
	float x;
	float y;
};
