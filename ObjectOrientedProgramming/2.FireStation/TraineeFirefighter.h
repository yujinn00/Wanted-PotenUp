#pragma once

#include "Firefighter.h"

// ���� �ҹ��
class TraineeFirefighter : public Firefighter
{
public:
	TraineeFirefighter(const std::string& name, bool hoseTrainedOnFire = false)
		: Firefighter(name), hoseTrainedOnFire(hoseTrainedOnFire)
	{
	}

protected:
	// ȣ�� �ѱ�
	virtual void TurnOnHose() override
	{
		if (hoseTrainedOnFire)
		{
			std::cout << "���� ������ �ֽ��ϴ�.\n";
		}
		else
		{
			std::cout << "���� ������ ������ Ƣ�� �ֽ��ϴ�.\n";
		}
	}

	// ȣ�� ����
	virtual void TrainHoseOnFire() override
	{
		hoseTrainedOnFire = true;
		std::cout << "ȣ���� ���� �߻��� ���� �ܳ��ϰ� �ֽ��ϴ�.\n";
	}
	
private:
	// ȣ���� �ҿ� ��Ȯ�ϰ� ���صǴ��� ���θ� ����
	bool hoseTrainedOnFire = false;
};
