#pragma once

#include "Firetruck.h"

#include <iostream>
#include <string>

class Firefighter
{
public:
	/*
	�θ� ������ ȣ��
	�ڽ� ������ ȣ��
	�ڽ� �Ҹ��� ȣ��
	�θ� �Ҹ��� ȣ��
	*/
	/*
	���� �Լ��� �ϳ��� �ִٸ�,
	�Ҹ��ڵ� �������� �����ؾ� ��
	*/
	Firefighter(const std::string& name)
		: name(name)
	{
	}

	virtual ~Firefighter() = default;

	// �� ���� (ExtinguishFire)
	virtual void ExtinguishFire()
	{
		std::cout << name << " �ҹ���� ���� ���� �ֽ��ϴ�.\n";
	}

	// ���� (Drive)
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// ������ Ȯ��
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// �̵�
		truckToDrive->Drive(position);
	}

	// ���� �� ����
	const std::string GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

private:
	std::string name;
};
