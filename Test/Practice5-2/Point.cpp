#include "Point.h"

Point::Point(int x, int y)
	: x(x), y(y)
{
}

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}
