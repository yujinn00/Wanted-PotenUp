#include <iostream>

// �޸� ���� Ȯ���� ���� ��� ����
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �޸� ���� �ڵ尡 �� ��° ������ Ȯ���ϱ� ���� �ҽ� �ڵ�
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define new new
#endif

class Player {
private:
	int x, y;
	int speed;
public:
	Player() : x(0), y(0), speed(1) {
		std::cout << "������ ȣ��\n";
	}

	~Player() {
		std::cout << "�Ҹ��� ȣ��\n";
	}

	// �̵��� ��ŭ�� ���� �Է� �޾Ƽ� ��ǥ�� �̵���Ű�� �Լ�
	void Move(int x, int y) { // int x, int y: ����
		this->x += x; // this->x: ��ġ
		this->y += y; // this->y: ��ġ
	}
};

int main() {
	// �޸� ���� Ȯ���� ���� �ҽ� �ڵ� (��ü ��Ʈ Ȯ��)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// �ش� ������� ���� ������Ŵ
	//_CrtSetBreakAlloc(158);

	// ��ü / ��ü / ������Ʈ / �ν��Ͻ�
	// �Ϲ���
	//Player player1;
	// �����
	Player player1 = Player(); // ������ ����� ȣ�� ��ȣ !!!!!!!!!!
	player1.Move(10, 20);

	// ���� �Ҵ�
	Player* player2 = new Player();
	//delete player2;
	//player2 = nullptr; // delete Ű����� �������ְ�, �� �ڿ� �̰ͱ��� ���ִ� ���� ��ȣ !!!!!!!!!!

	std::cin.get();

	return 0;
}
