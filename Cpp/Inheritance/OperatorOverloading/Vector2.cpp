#include "Vector2.h"

Vector2::Vector2()
	: x(0.0f), y(0.0f)
{
}

Vector2::Vector2(float x, float y)
	: x(x), y(y)
{
}

Vector2 Vector2::Add(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::Multiply(const Vector2& other)
{
	//return *this * other;
	return Vector2(x * other.x, y * other.y);
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator*(const Vector2& other)
{
	//return this->Multiply(other);
	return Vector2(x * other.x, y * other.y);
}

float Vector2::operator[](int index)
{
	return 0.0f;
}

float Vector2::GetX() const
{
	return x;
}

float Vector2::GetY() const
{
	return y;
}
