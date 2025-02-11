#pragma once

#include <iostream>

#include "Point.h"
#include "Ladder.h"
#include "Hose.h"

// ���� ���� (��� ��ȯ ���� ���� + ������ �ӵ� ����)
class FirefighterBase;
class Firetruck
{
public:
	Firetruck()
	{
		ladder = new Ladder(10.0f);
	}

	~Firetruck()
	{
		delete ladder;
	}

	void Drive(const Point& position)
	{
		if (driver == nullptr)
		{
			return;
		}

		std::cout << position << " ��ġ�� �ҹ����� �̵����Դϴ�.\n";
	}

	const Ladder* GetLadder() const { return ladder; }

	const Hose* GetHose() const { return hose; }
	void SetHose(Hose* hose) { this->hose = hose; }

	FirefighterBase* GetDriver() const { return driver; }
	void SetDriver(FirefighterBase* driver) { this->driver = driver; }

private:
	FirefighterBase* driver = nullptr;
	Ladder* ladder = nullptr;
	Hose* hose = nullptr;
};
