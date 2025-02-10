#pragma once

#include <iostream>

class Time
{
public:
	Time(int hour, int minute = 0, int second = 0)
		: hour(hour), minute(minute), second(second)
	{
	}

	void ShowTime()
	{
		std::cout << "[" << hour << "시 "
			<< minute << "분 "
			<< second << "초]\n";
	}

	void ShowTimeInSeconds()
	{
		std::cout << (hour * 60 * 60) + (minute * 60) + second << "초\n";
	}

private:
	int hour = 0;
	int minute = 0;
	int second = 0;
};
