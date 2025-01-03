#include "Rectangle.h"
#include "Circle.h"

#include <iostream>

int main()
{
	Rectangle rect = Rectangle(3, 4);
	std::cout << "면적: " << rect.GetArea() << "\n";
	std::cout << "둘레: " << rect.GetGirth() << "\n";

	Circle circle = Circle(5);
	std::cout << "면적: " << circle.GetArea() << "\n";
	std::cout << "둘레: " << circle.GetGirth() << "\n";
}
