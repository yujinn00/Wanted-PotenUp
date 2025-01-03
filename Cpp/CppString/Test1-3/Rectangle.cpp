#include "Rectangle.h"

Rectangle::Rectangle(int width, int height)
	: width(width), height(height)
{
}

double Rectangle::GetArea() const
{
	return width * height;
}

double Rectangle::GetGirth() const
{
	return width * 2 + height * 2;
}
