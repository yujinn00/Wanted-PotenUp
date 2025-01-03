#include <iostream>

// Ÿ�� ������ ���� ��ũ��
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }

class Actor
{
	RTTI(Actor)

public:
	// ���� �Լ� �߰� (������ ����)
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n\n";
	}

protected:
	int a;
};

class Player : public Actor
{
	RTTI(Player)
};

int main()
{
	// ��ü ����
	Actor* actor = new Actor();
	Player* player = new Player();

	// �� ĳ����
	Actor* actorPointer1 = reinterpret_cast<Actor*>(player); // ���� �� ��ȯ ���ص� ��
	Actor* actorPointer2 = (Actor*)player; // ���� �� ��ȯ ���ص� ��
	Actor* actorPointer3 = player;

	// �ٿ� ĳ���� OK
	Player* playerPointer1 = static_cast<Player*>(actorPointer3);
	Player* playerPointer2 = reinterpret_cast<Player*>(actorPointer3);

	// �ٿ� ĳ���� Not OK
	Player* playerPointer3 = dynamic_cast<Player*>(actorPointer3); // ���� �߻� (��, �⺻ Ŭ������ "���� �Լ�" ����� ���� �߻� X)
	//Player* playerPointer4 = static_cast<Player*>(actor); // ������ �� ������, �� ��ȯ ����

	// ���� ó��
	// dynamic_cast: ���� ..?
	if (playerPointer3)
	{
		// �Լ� ȣ��
		playerPointer3->PrintValue();
	}
	else
	{
		std::cout << "�� ��ȯ ����\n\n";
	}

	//////////////////////////////////////////////////////////////

	// typeid
	const type_info& info = typeid(actorPointer3);
	std::cout << "Ÿ�� �̸�: " << info.name() << "\n\n";

	//////////////////////////////////////////////////////////////

	std::cout << "Actor Ÿ��: " << actor->ClassName() << "\n";
	std::cout << "Player Ÿ��: " << player->ClassName() << "\n";
	std::cout << "Player Ÿ��: " << actorPointer3->ClassName() << "\n\n";


	// Ÿ�� ��
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "Ÿ�� ����\n\n";
	}
	else
	{
		std::cout << "Ÿ�� �ٸ�\n\n";
	}
}
