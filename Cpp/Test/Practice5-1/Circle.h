#pragma once

#include "Point.h"

class Circle : public Point
{
public:
	Circle(int x, int y, float radius);
	void ShowData() const;

private:
	float radius;
};
