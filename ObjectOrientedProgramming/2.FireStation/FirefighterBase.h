#pragma once

#include "Firetruck.h"
#include "INamedPerson.h"

#include <iostream>
#include <string>

class FirefighterBase : public INamedPerson
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
	FirefighterBase(const std::string& name)
		: name(name)
	{
	}

	// 불 끄기 (순수 가상 함수)
	virtual void ExtinguishFire() = 0;

	// 운전
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
	virtual std::string GetName() const override { return name; }
	void SetName(const std::string& name) { this->name = name; }

protected:
	std::string name;
};
