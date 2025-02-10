#pragma once

#include "Firetruck.h"

#include <iostream>
#include <string>

class Firefighter
{
public:
	/*
	부모 생성자 호출
	자식 생성자 호출
	자식 소멸자 호출
	부모 소멸자 호출
	*/
	/*
	가상 함수가 하나라도 있다면,
	소멸자도 가상으로 선언해야 함
	*/
	Firefighter(const std::string& name)
		: name(name)
	{
	}

	virtual ~Firefighter() = default;

	// 불 끄기 (ExtinguishFire)
	virtual void ExtinguishFire()
	{
		std::cout << name << " 소방관이 불을 끄고 있습니다.\n";
	}

	// 운전 (Drive)
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// 운전자 확인
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// 이동
		truckToDrive->Drive(position);
	}

	// 게터 및 세터
	const std::string GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

private:
	std::string name;
};
