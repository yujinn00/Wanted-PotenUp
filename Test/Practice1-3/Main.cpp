#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

int main()
{
	Rectangle rect = Rectangle(3, 4);
	std::cout << "����: " << rect.GetArea() << "\n";
	std::cout << "�ѷ�: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);
	std::cout << "����: " << circle.GetArea() << "\n";
	std::cout << "�ѷ�: " << circle.GetGirth() << "\n";
}
