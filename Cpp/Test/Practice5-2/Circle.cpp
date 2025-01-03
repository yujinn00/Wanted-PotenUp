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
	std::cout << "�߽� ��ǥ: (" << point->GetX() << ", " << point->GetY() << ")\n";
	std::cout << "������: " << radius << "\n";
	std::cout << "���� ����: " << radius * radius * 3.141592f << "\n";
}
