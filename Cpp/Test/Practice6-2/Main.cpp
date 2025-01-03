#include "Vector2.h"

#include <iostream>

int main()
{
	Vector2 position1 = Vector2(3.0f, 1.0f);
	Vector2 position2 = Vector2(3.0f, 1.0f);
	Vector2 position3 = Vector2(5.0f, 10.0f);

	if (position1 == position2)
	{
		std::cout << "position1과 position2는 같다.\n";
	}
	else
	{
		std::cout << "position1과 position2는 다르다.\n";
	}

	if (position2 != position3)
	{
		std::cout << "position2와 position3은 다르다.\n";
	}
	else
	{
		std::cout << "position2와 position3은 같다.\n";
	}
}
