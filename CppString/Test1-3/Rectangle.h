#pragma once

class Rectangle
{
private:
	int width;
	int height;

public:
	Rectangle(int width, int height);
	double GetArea() const;
	double GetGirth() const;
};
