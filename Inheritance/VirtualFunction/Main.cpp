#include "Entity/Entity.h"
#include "Entity/Player.h"

#include <iostream>

int main()
{
	// Entity ��ü ����
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player ��ü ����
	//Player* player = new Player("RonnieJ");
	IEntity* player = new Player("RonnieJ"); // ��ĳ����
	//std::cout << player->GetName() << "\n";

	// �޸� ����
	//delete entity;
	delete player;

	return 0;
}    