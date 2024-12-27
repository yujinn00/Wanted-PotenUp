#include "Entity/Entity.h"
#include "Entity/Player.h"

#include <iostream>

int main()
{
	// Entity 객체 생성
	Entity* entity = new Entity();

	// Player 객체 생성
	Player* player = new Player("Ronnie");

	// 다형성
	Entity* entity2 = player; // entity2는 메모리 해제하면 안됨

	delete entity;
	delete player;

	return 0;
}