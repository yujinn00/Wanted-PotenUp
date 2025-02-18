#pragma region [���� 1��]
//#include <iostream>
//
//int main() {
//	int sum = 0;
//
//	for (int i = 2; i <= 100; i += 2) {
//		sum += i;
//	}
//
//	std::cout << sum << "\n";
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 2��]
//#include <iostream>
//
//int main() {
//	for (int i = 0; i < 5; i++) {
//		for (int j = i; j >= 0; j--) {
//			std::cout << "*";
//		}
//
//		std::cout << "\n";
//	}
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 3��]
//#include <iostream>
//
//void swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//	int a = 3;
//	int b = 5;
//
//	std::cout << a << " " << b << "\n";
//
//	swap(a, b);
//
//	std::cout << a << " " << b << "\n";
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 4��]
//#include <iostream>
//
//static void PrintReverse(const char* str, int size) {
//	for (int i = 0; i < size; i++) {
//		std::cout << str[size - (i + 1)];
//	}
//
//	std::cout << "\n";
//}
//
//int main() {
//	PrintReverse("abcde", 5);
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 5��]
//#include <iostream>
//
//static char charToLower(char upperCase) {
//	upperCase += 32;
//	return upperCase;
//}
//
//static char charToUpper(char lowerCase) {
//	lowerCase -= 32;
//	return lowerCase;
//}
//
//int main() {
//	char lower, upper;
//
//	std::cout << "�ҹ��ڸ� �Է��ϼ���.\n";
//
//	for (;;) {
//		std::cin >> lower;
//
//		if (lower >= 97 && lower <= 122) {
//			std::cout << "�Է��Ͻ� ������ �빮�ڴ� " << charToUpper(lower) << "�Դϴ�.\n\n";
//			break;
//		} else {
//			std::cout << "�Է��Ͻ� ���ڴ� �ҹ��ڰ� �ƴմϴ�. �ҹ��ڸ� �ٽ� �Է��ϼ���.\n";
//			std::cin.clear();
//			std::cin.ignore(10, '\n');
//		}
//	}
//
//	std::cout << "�빮�ڸ� �Է��ϼ���.\n";
//
//	for (;;) {
//		std::cin >> upper; 
//
//		if (upper >= 65 && upper <= 90) {
//			std::cout << "�Է��Ͻ� ������ �ҹ��ڴ� " << charToLower(upper) << "�Դϴ�.\n";
//			break;
//		} else {
//			std::cout << "�Է��Ͻ� ���ڴ� �빮�ڰ� �ƴմϴ�. �빮�ڸ� �ٽ� �Է��ϼ���.\n";
//			std::cin.clear();
//			std::cin.ignore(10, '\n');
//		}
//	}
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 6��]
//#include <iostream>
//
//bool HasSameCharacter(const char* testString, int stringLength) {
//	bool flag[26] = { false };
//
//	for (int i = 0; i < stringLength; i++) {
//		int idx = testString[i] - 'a';
//
//		if (flag[idx]) {
//			return true;
//		} else {
//			flag[idx] = true;
//		}
//	}
//
//	return false;
//}
//
//int main() {
//	char str[10];
//	int length = 0;
//
//	std::cout << "�ߺ��� �˻��� ���ڿ��� �Է����ּ���.\n";
//	std::cin >> str;
//
//	while (str[length] != '\0') {
//		length++;
//	}
//
//	if (HasSameCharacter(str, length)) {
//		std::cout << "���ڿ� �ߺ� �˻� ����� �����Դϴ�.\n";
//	} else {
//		std::cout << "���ڿ� �ߺ� �˻� ����� �����Դϴ�.\n";
//	}
//
//	return 0;
//}
#pragma endregion

#pragma region [���� 7��]
//#include <iostream>
//
//class Entity {
//protected:
//	std::string name;
//	int hp;
//	int mp;
//	int ad;
//
//public:
//	Entity(const std::string& name, int hp, int mp, int ad)
//		: name(name), hp(hp), mp(mp), ad(ad) {}
//	virtual ~Entity() {}
//
//	int getHp() const { return hp; }
//	int getMp() const { return mp; }
//	int getAd() const { return ad; }
//
//	virtual void attack(Entity& target) {
//		std::cout << name << "��(��) " << target.name << "���� " << ad << "�� �������� �������ϴ�.\n";
//		target.takeDamage(ad);
//	}
//
//	virtual void takeDamage(int ad) {
//		hp -= ad;
//
//		if (hp <= 0) {
//			hp = 0;
//			std::cout << name << "��(��) ����߽��ϴ�.\n";
//		} else {
//			std::cout << name << "��(��) " << ad << "�� ���ظ� �Ծ����ϴ�. ���� ü��: " << hp << "\n\n";
//		}
//	}
//
//	bool isAlive() const {
//		return hp > 0;
//	}
//};
//
//class Player : public Entity {
//private:
//	int gold;
//
//public:
//	Player()
//		: Entity("�÷��̾�", 1000, 0, 10), gold(0) {}
//
//	void getGold(int gold) {
//		this->gold += gold;
//		std::cout << name << "��(��) " << gold << "�� ��带 ������ϴ�. ���� ���: " << this->gold << " Gold\n\n\n";
//	}
//};
//
//class Monster : public Entity {
//private:
//	int reward;
//
//public:
//	Monster(const std::string& name, int hp, int mp, int ad, int reward)
//		: Entity(name, hp, mp, ad), reward(reward) {}
//
//	int getReward() const {
//		return reward;
//	}
//};
//
//class Slime : public Monster {
//public:
//	Slime()
//		: Monster("������", 10, 0, 20, 1) {}
//};
//
//class Goblin : public Monster {
//public:
//	Goblin()
//		: Monster("���", 20, 0, 10, 2) {}
//};
//
//class Boar : public Monster {
//public:
//	Boar()
//		: Monster("�����", 20, 0, 20, 3) {}
//};
//
//int main() {
//	Player player;
//
//	Slime slime;
//	Goblin goblin;
//	Boar boar;
//
//	std::cout << "=== ���� ���� ===\n\n\n";
//	std::cout << "������ �����մϴ�.\n\n\n";
//
//	std::cout << "=== �����Ӱ��� ���� ���� ===\n\n\n";
//	while (slime.isAlive() && player.isAlive()) {
//		player.attack(slime);
//		if (slime.isAlive()) {
//			slime.attack(player);
//		}
//	}
//	if (!slime.isAlive()) {
//		player.getGold(slime.getReward());
//	}
//
//	std::cout << "=== ������� ���� ���� ===\n\n\n";
//	std::cout << "�����(��) �������ϴ�.\n\n\n";
//
//	std::cout << "=== ��������� ���� ���� ===\n\n\n";
//	while (boar.isAlive() && player.isAlive()) {
//		player.attack(boar);
//		if (boar.isAlive()) {
//			boar.attack(player);
//		}
//	}
//	if (!boar.isAlive()) {
//		player.getGold(boar.getReward());
//	}
//
//	std::cout << "=== ���� Ŭ���� ===\n\n\n";
//	std::cout << "��� ���͸� óġ�߽��ϴ�.\n";
//
//	return 0;
//}
#pragma endregion

class Test
{
public:
	Test* operator=(const Test& other)
	{
		if (this != &other)
		{
			data = other.data;
		}
		return this;
	}

private:
	int data;
};

int main()
{
	Test a, b, c;
	a = *(b = c); // ������ ����: b = c�� ����� a�� �����ϴ� ���� �߻�
}