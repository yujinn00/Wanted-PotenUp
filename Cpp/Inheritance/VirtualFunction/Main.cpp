#include "Entity/Entity.h"
#include "Entity/Player.h"

#include <iostream>

int main()
{
	// Entity 객체 생성
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player 객체 생성
	//Player* player = new Player("RonnieJ");
	IEntity* player = new Player("RonnieJ"); // 업캐스팅
	//std::cout << player->GetName() << "\n";

	// 메모리 해제
	//delete entity;
	delete player;

	return 0;
}    