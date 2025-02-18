#pragma region [문제 1번]
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

#pragma region [문제 2번]
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

#pragma region [문제 3번]
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

#pragma region [문제 4번]
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

#pragma region [문제 5번]
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
//	std::cout << "소문자를 입력하세요.\n";
//
//	for (;;) {
//		std::cin >> lower;
//
//		if (lower >= 97 && lower <= 122) {
//			std::cout << "입력하신 문자의 대문자는 " << charToUpper(lower) << "입니다.\n\n";
//			break;
//		} else {
//			std::cout << "입력하신 문자는 소문자가 아닙니다. 소문자를 다시 입력하세요.\n";
//			std::cin.clear();
//			std::cin.ignore(10, '\n');
//		}
//	}
//
//	std::cout << "대문자를 입력하세요.\n";
//
//	for (;;) {
//		std::cin >> upper; 
//
//		if (upper >= 65 && upper <= 90) {
//			std::cout << "입력하신 문자의 소문자는 " << charToLower(upper) << "입니다.\n";
//			break;
//		} else {
//			std::cout << "입력하신 문자는 대문자가 아닙니다. 대문자를 다시 입력하세요.\n";
//			std::cin.clear();
//			std::cin.ignore(10, '\n');
//		}
//	}
//
//	return 0;
//}
#pragma endregion

#pragma region [문제 6번]
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
//	std::cout << "중복을 검사할 문자열을 입력해주세요.\n";
//	std::cin >> str;
//
//	while (str[length] != '\0') {
//		length++;
//	}
//
//	if (HasSameCharacter(str, length)) {
//		std::cout << "문자열 중복 검사 결과는 있음입니다.\n";
//	} else {
//		std::cout << "문자열 중복 검사 결과는 없음입니다.\n";
//	}
//
//	return 0;
//}
#pragma endregion

#pragma region [문제 7번]
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
//		std::cout << name << "이(가) " << target.name << "에게 " << ad << "의 데미지를 입혔습니다.\n";
//		target.takeDamage(ad);
//	}
//
//	virtual void takeDamage(int ad) {
//		hp -= ad;
//
//		if (hp <= 0) {
//			hp = 0;
//			std::cout << name << "이(가) 사망했습니다.\n";
//		} else {
//			std::cout << name << "이(가) " << ad << "의 피해를 입었습니다. 남은 체력: " << hp << "\n\n";
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
//		: Entity("플레이어", 1000, 0, 10), gold(0) {}
//
//	void getGold(int gold) {
//		this->gold += gold;
//		std::cout << name << "이(가) " << gold << "의 골드를 얻었습니다. 현재 골드: " << this->gold << " Gold\n\n\n";
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
//		: Monster("슬라임", 10, 0, 20, 1) {}
//};
//
//class Goblin : public Monster {
//public:
//	Goblin()
//		: Monster("고블린", 20, 0, 10, 2) {}
//};
//
//class Boar : public Monster {
//public:
//	Boar()
//		: Monster("멧돼지", 20, 0, 20, 3) {}
//};
//
//int main() {
//	Player player;
//
//	Slime slime;
//	Goblin goblin;
//	Boar boar;
//
//	std::cout << "=== 게임 시작 ===\n\n\n";
//	std::cout << "전투를 시작합니다.\n\n\n";
//
//	std::cout << "=== 슬라임과의 전투 시작 ===\n\n\n";
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
//	std::cout << "=== 고블린과의 전투 시작 ===\n\n\n";
//	std::cout << "고블린이(가) 도망갑니다.\n\n\n";
//
//	std::cout << "=== 멧돼지와의 전투 시작 ===\n\n\n";
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
//	std::cout << "=== 게임 클리어 ===\n\n\n";
//	std::cout << "모든 몬스터를 처치했습니다.\n";
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
	a = *(b = c); // 컴파일 에러: b = c의 결과를 a로 대입하는 순간 발생
}