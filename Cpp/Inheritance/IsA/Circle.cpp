#include "Circle.h"

#include <iostream>

Circle::Circle(int x, int y, double radius)
	: Point(x, y), radius(radius)
{
}

void Circle::ShowData()
{
	std::cout << "�߽� ��ǥ: (" << x << ", " << y << ")\n";
	std::cout << "������: " << radius << "\n";
	std::cout << "���� ����: " << radius * radius * 3.141592f << "\n";
}
