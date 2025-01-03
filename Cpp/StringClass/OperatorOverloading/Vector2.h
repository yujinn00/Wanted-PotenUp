#pragma once

#include <iostream>

class Vector2
{
private:
	float x;
	float y;
public:
	Vector2(float x, float y);

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	Vector2 operator/(const Vector2& other);

	Vector2 operator+=(const Vector2& other);

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.x << ", " << vector.y << ")\n";
		return os;
	}
};
