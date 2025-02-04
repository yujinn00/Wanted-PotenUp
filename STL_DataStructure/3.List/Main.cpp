#include <iostream>
#include <list>
#include <algorithm>

// ������ ����ü
struct Item
{
	Item(int code = 0, int price = 0)
		: code(code), price(price)
	{
	}

	int code = 0;		// ������ �ڵ�
	int price = 0;		// ������ ����
};

// ������ ��¿� ������ �����ε�
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "�ڵ�: " << item.code << ", ����: " << item.price;
}

// ������ �ڵ带 �������� �����ϴ� �Լ� ��ü
struct ItemLessComparer
{
	bool operator()(const Item& left, const Item& right)
	{
		return left.code < right.code;
	}
};

int main()
{
	// ����Ʈ ����
	std::list<Item> itemList;

	// ������ �߰�
	itemList.emplace_front(Item(1, 200));
	itemList.emplace_front(Item(2, 1000));

	// �ڿ� �߰�
	itemList.emplace_back(Item(3, 3000));
	itemList.emplace_back(Item(4, 4500));

	// ���
	for (/*std::list<Item>::iterator*/ auto iterator = itemList.begin();
		iterator != itemList.end();
		++iterator)
	{
		// Iterator�� �������̱� ������ �����͸� ���� ���� *�� �ٿ��� ��
		std::cout << *iterator << "\n";
	}

	// ����
	itemList.pop_front();

	// �� �տ� �ִ� ������ �б�
	Item& frontItem = itemList.front();

	// ���
	std::cout << frontItem << "\n";

	itemList.emplace_back(Item(6, 4500));
	itemList.emplace_back(Item(8, 9000));
	itemList.emplace_back(Item(5, 800));
	itemList.emplace_back(Item(7, 700));

	// ����
	ItemLessComparer lessComparer;
	itemList.sort(lessComparer);

	// ���� �� ���
	std::cout << "-----���� �� ���-----\n";
	for (auto& item : itemList)
	{
		std::cout << item << "\n";
	}

	// ����2
	// HTTP -> �α��� ��û
	itemList.sort
	(
		[](const Item& left, const Item& right) /*-> bool*/
		{
			return left.price > right.price;
		}
	);

	// ����2 �� ���
	std::cout << "-----����2 �� ���-----\n";
	for (auto& item : itemList)
	{
		std::cout << item << "\n";
	}

	std::cin.get();
}
