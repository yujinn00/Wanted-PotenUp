#include "Circle.h"
#include "Point.h"

#include <iostream>

Circle::Circle(int x, int y, float radius)
	: point(new Point(x, y)), radius(radius)
{
}

Circle::~Circle()
{
	delete point;
}

void Circle::ShowData() const
{
	std::cout << "중심 좌표: (" << point->GetX() << ", " << point->GetY() << ")\n";
	std::cout << "반지름: " << radius << "\n";
	std::cout << "원의 넓이: " << radius * radius * 3.141592f << "\n";
}
