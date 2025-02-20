#pragma once

#include <iostream>

#include "Point.h"
#include "Ladder.h"
#include "Hose.h"

// 전방 선언 (헤더 순환 참조 금지 + 컴파일 속도 개선)
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

		std::cout << position << " 위치로 소방차가 이동중입니다.\n";
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
