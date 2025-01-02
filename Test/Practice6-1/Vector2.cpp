#include "Vector2.h"

Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const Vector2& other)
{
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator/(const Vector2& other)
{
	return Vector2(x / other.x, y / other.y);
}

std::ostream& operator<<(std::ostream& os, const Vector2& other)
{
	os << "x: " << other.x << ", y: " << other.y << "\n";
	return os;
}
