#include "Entity/Entity.h"
#include "Entity/Player.h"

#include <iostream>

int main()
{
	// Entity ��ü ����
	Entity* entity = new Entity();

	// Player ��ü ����
	Player* player = new Player("Ronnie");

	// ������
	Entity* entity2 = player; // entity2�� �޸� �����ϸ� �ȵ�

	delete entity;
	delete player;

	return 0;
}