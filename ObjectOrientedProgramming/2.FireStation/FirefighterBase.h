#pragma once

#include "Firetruck.h"
#include "INamedPerson.h"

#include <iostream>
#include <string>

class FirefighterBase : public INamedPerson
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
	FirefighterBase(const std::string& name)
		: name(name)
	{
	}

	// �� ���� (���� ���� �Լ�)
	virtual void ExtinguishFire() = 0;

	// ����
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
	virtual std::string GetName() const override { return name; }
	void SetName(const std::string& name) { this->name = name; }

protected:
	std::string name;
};
