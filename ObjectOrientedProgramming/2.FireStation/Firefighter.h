#pragma once

#include "FirefighterBase.h"

class Firefighter : public FirefighterBase
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
		: FirefighterBase(name)
	{
	}

	virtual ~Firefighter() = default;

	// 불 끄기
	virtual void ExtinguishFire()
	{
		std::cout << name << " 소방관이 불을 끄고 있습니다.\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

protected:
	// 호스 켜기
	virtual void TurnOnHose()
	{
		std::cout << "불이 꺼지고 있습니다.\n";
	}

	// 호스 조준
	virtual void TrainHoseOnFire()
	{
		std::cout << "호스를 불이 발생한 곳에 겨냥하고 있습니다.\n";
	}
};
