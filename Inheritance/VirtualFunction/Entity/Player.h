#pragma once

#include "Entity.h"
#include "IMovable.h"

// Entity 클래스를 부모로 지정
// 미들웨어 (운영체제 위에서 동작하는 프로그램)
class Player : public IEntity, public IMovable // 다중 상속
{
public:
	Player(const char* name);
	~Player();

	// 가상 함수
	virtual const char* GetName() override { return name; }

	virtual void Move(int xAmount, int yAmount) = 0;

private:
	char* name;
};