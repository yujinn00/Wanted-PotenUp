#pragma once

// 클래스 선언
class IEntity
{
public:
	//Entity();
	//virtual ~Entity(); // 가상 소멸자 선언

	//void Move(int xAmount, int yAmount);
	
	// 가상 함수
	//virtual const char* GetName() { return "Entity"; }

	// 순수 가상 함수
	// 목적: 이 함수를 필수적으로 구현하도록 강제함
	virtual const char* GetName() = 0;

	//virtual void Test() {
	//	// ....
	//}

protected:
	int x;
	int y;
};