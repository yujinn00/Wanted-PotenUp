#include "Circle.h"

#include <iostream>

Circle::Circle(int x, int y, float radius)
	: Point(x, y), radius(radius)
{
}

void Circle::ShowData() const
{
	std::cout << "중심 좌표: (" << x << ", " << y << ")\n";
	std::cout << "반지름: " << radius << "\n";
	std::cout << "원의 넓이: " << radius * radius * 3.141592f << "\n";
}
