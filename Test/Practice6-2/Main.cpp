#include "Vector2.h"

#include <iostream>

int main()
{
	Vector2 position1 = Vector2(3.0f, 1.0f);
	Vector2 position2 = Vector2(3.0f, 1.0f);
	Vector2 position3 = Vector2(5.0f, 10.0f);

	if (position1 == position2)
	{
		std::cout << "position1�� position2�� ����.\n";
	}
	else
	{
		std::cout << "position1�� position2�� �ٸ���.\n";
	}

	if (position2 != position3)
	{
		std::cout << "position2�� position3�� �ٸ���.\n";
	}
	else
	{
		std::cout << "position2�� position3�� ����.\n";
	}
}
