#include "Circle.h"

#include <iostream>

Circle::Circle(int x, int y, float radius)
	: Point(x, y), radius(radius)
{
}

void Circle::ShowData() const
{
	std::cout << "�߽� ��ǥ: (" << x << ", " << y << ")\n";
	std::cout << "������: " << radius << "\n";
	std::cout << "���� ����: " << radius * radius * 3.141592f << "\n";
}
