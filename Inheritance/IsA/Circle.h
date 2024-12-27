#pragma once

#include "Point.h"

class Circle : public Point
{
private:
	double radius;

public:
	Circle(int x, int y, double radius);
	void ShowData();
};