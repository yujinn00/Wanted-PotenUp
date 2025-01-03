#include <iostream>
#include <string>

class NPC
{
public:
	NPC() { std::cout << "�⺻ ������\n"; }
	NPC(int npcCode, const std::string& name) { std::cout << "���� �ִ� ������\n"; }
	NPC(const NPC& other) { std::cout << "���� ������\n"; }
	NPC& operator=(const NPC& other) { std::cout << "���� ������\n"; return *this; }
	NPC(NPC&& other) { std::cout << "Move ������\n"; }
	NPC& operator=(NPC&& other) { std::cout << "Move ���� ������\n"; return *this; }

	int npcCode;
	std::string name;
};

int main()
{
	std::cout << "1\n";
	NPC npc1(NPC(10, "Orge1"));

	std::cout << "\n2\n";
	NPC npc2(11, "Orge2");
	NPC npc3 = npc2;

	std::cout << "\n3\n";
	NPC npc4;
	NPC npc5;
	npc5 = npc4;

	std::cout << "\n4\n";
	NPC npc6 = NPC(12, "Orge3");

	std::cout << "\n5\n";
	NPC npc7;
	NPC npc8;
	npc8 = std::move(npc7); // npc7�� ���� ��ü�� �ִ� ���̾��µ�, �� ���� �ӽ� ���� �Ǿ����

	std::cin.get();
}
