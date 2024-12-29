#pragma once

class Circle
{
private:
	int radius;

public:
	Circle(int radius);
	double GetArea() const;
	double GetGirth() const;
};
