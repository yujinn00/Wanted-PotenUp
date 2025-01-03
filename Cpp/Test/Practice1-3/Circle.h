#pragma once

class Circle
{
public:
	Circle(int radius);
	double GetArea() const;
	double GetGirth() const;

private:
	int radius;
};
