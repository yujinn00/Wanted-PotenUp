// 헤더 파일 포함
#include "Entity.h"

#include <iostream>

// Header <-> CPP 파일 전환 단축키
// Ctrl + K + O

Entity::Entity()
	: x(0), y(0)
{
	std::cout << "Entity() called\n";
}

Entity::~Entity()
{
	std::cout << "~Entity() called\n";
}

void Entity::Move(int xAmount, int yAmount)
{
	x += xAmount;
	y += yAmount;
}