#pragma once

class Rectangle
{
public:
	Rectangle(int width, int height);
	double GetArea() const;
	double GetGirth() const;

private:
	int width;
	int height;
};
