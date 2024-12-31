#pragma once

class Point;

class Circle
{
public:
	Circle(int x, int y, float radius);
	~Circle();

	void ShowData() const;

private:
	Point* point;
	float radius;
};
