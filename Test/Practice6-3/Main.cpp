#include "Vector2.h"

#include <iostream>

int main()
{
	Vector2 position = Vector2(4.0f, 3.0f);
	Vector2 direction = Vector2(1.0f, 1.0f);
	position += direction;
	std::cout << position << "\n";
}
