#pragma once

#include "FirefighterBase.h"

class Firefighter : public FirefighterBase
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
		: FirefighterBase(name)
	{
	}

	virtual ~Firefighter() = default;

	// �� ����
	virtual void ExtinguishFire()
	{
		std::cout << name << " �ҹ���� ���� ���� �ֽ��ϴ�.\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

protected:
	// ȣ�� �ѱ�
	virtual void TurnOnHose()
	{
		std::cout << "���� ������ �ֽ��ϴ�.\n";
	}

	// ȣ�� ����
	virtual void TrainHoseOnFire()
	{
		std::cout << "ȣ���� ���� �߻��� ���� �ܳ��ϰ� �ֽ��ϴ�.\n";
	}
};
