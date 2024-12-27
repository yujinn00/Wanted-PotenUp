#pragma once

#include "Entity.h"
#include "IMovable.h"

// Entity Ŭ������ �θ�� ����
// �̵���� (�ü�� ������ �����ϴ� ���α׷�)
class Player : public IEntity, public IMovable // ���� ���
{
public:
	Player(const char* name);
	~Player();

	// ���� �Լ�
	virtual const char* GetName() override { return name; }

	virtual void Move(int xAmount, int yAmount) = 0;

private:
	char* name;
};