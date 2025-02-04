// �ؽ� ���̺� ����� ���� ��� ��Ŭ���
#include <iostream>
#include <unordered_map>

// ���� ĳ���� Ŭ����
class GameCharacter
{
public:
	// ������
	GameCharacter() = default;
	GameCharacter(int code, int level, int money)
		: code(code), level(level), money(money)
	{
	}

	// Getter
	const int Code() const { return code; }
	const int Level() const { return level; }
	const int Money() const { return money; }

	// ����� ���� ������ �����ε�
	friend std::ostream& operator<<(
		std::ostream& os,
		const GameCharacter& character
		)
	{
		return os << "�ڵ�: " << character.code
			<< " | ����: " << character.level
			<< " | ��: " << character.money << "\n";
	}

private:
	int code = 0;
	int level = 0;
	int money = 0;
};

int main()
{
	// �ؽ� ���̺� ����
	std::unordered_map<int, GameCharacter> characters;

	// ������ �߰�
	GameCharacter character1(10, 1, 30000);
	//std::pair<int, GameCharacter> pair(character1.Code(), character1);
	characters.insert(std::make_pair(character1.Code(), character1));
	//characters.insert({ character1.Code(), character1 });

	GameCharacter character2(15, 3, 20000);
	//std::pair<int, GameCharacter> pair(character1.Code(), character1);
	characters.insert(
		std::make_pair(character2.Code(), character2)
	);

	// ���
	for (auto& pair : characters)
	{
		std::cout << pair.second;
	}

	// �˻�
	auto it = characters.find(20);

	// �˻��� �����ߴ��� Ȯ��
	if (it != characters.end())
	{
		// ĳ���� ���� ���
		std::cout << it->second;
	}
	else
	{
		std::cout << "Error: �˻��� �����߽��ϴ�.\n";
	}

	// �߰�
	characters[15] = GameCharacter(15, 35, 150000);

	// �˻�2
	auto result = characters[15];
	std::cout << result;

	std::cin.get();
}
