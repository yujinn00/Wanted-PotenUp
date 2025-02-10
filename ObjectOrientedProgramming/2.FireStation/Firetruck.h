#pragma once

#include <iostream>

#include "Point.h"
#include "Ladder.h"
#include "Hose.h"

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

	class Firefighter* GetDriver() const { return driver; }
	void SetDriver(class Firefighter* driver) { this->driver = driver; }

private:
	class Firefighter* driver = nullptr;
	Ladder* ladder = nullptr;
	Hose* hose = nullptr;
};
