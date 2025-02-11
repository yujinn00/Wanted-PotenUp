#pragma once

#include "FirefighterBase.h"

class FireChief : public FirefighterBase
{
public:
	FireChief(const std::string& name, FirefighterBase* numberOne = nullptr)
		: FirefighterBase(name), numberOne(numberOne)
	{
	}

	// �� ���� ���� �Լ�
	void TellFirefighterToExtinguishFire(FirefighterBase* colleague)
	{
		colleague->ExtinguishFire();
	}

	// ������
	virtual void ExtinguishFire() override
	{
		if (numberOne == nullptr)
		{
			return;
		}

		TellFirefighterToExtinguishFire(numberOne);
	}

	FirefighterBase* GetNumberOne() const { return numberOne; }
	void SetNumberOne(FirefighterBase* numberOne) { this->numberOne = numberOne; }

private:
	FirefighterBase* numberOne = nullptr;
};
