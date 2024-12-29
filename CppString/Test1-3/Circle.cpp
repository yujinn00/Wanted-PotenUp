#include "Circle.h"

Circle::Circle(int radius)
	: radius(radius)
{
}

double Circle::GetArea() const
{
	return radius * radius * 3.141582;
}

double Circle::GetGirth() const
{
	return 2 * 3.141592 * radius;
}
