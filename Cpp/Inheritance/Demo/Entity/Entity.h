#pragma once

// Ŭ���� ����
class Entity
{
public:
	Entity();
	~Entity();

	void Move(int xAmount, int yAmount);

protected:
	int x;
	int y;
};