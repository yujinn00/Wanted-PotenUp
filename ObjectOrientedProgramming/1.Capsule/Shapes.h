#pragma once

class Rectangle
{
public:
	Rectangle(float width, float height)
		: width(width), height(height)
	{
	}

	float GetArea()
	{
		return width * height;
	}

	float GetSize()
	{
		return 2.0f * (width + height);
	}

private:
	float width = 0.0f;
	float height = 0.0f;
};

class Circle
{
public:
	Circle(float radius)
		: radius(radius)
	{
	}

	float GetArea()
	{
		return radius * radius * PI;
	}

	float GetSize()
	{
		return 2.0f * PI * radius;
	}

private:
	float radius = 0.0f;
	const float PI = 3.141592f;
};
