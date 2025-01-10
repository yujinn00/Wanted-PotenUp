#include <iostream>
#include "HashTable.h"

int main()
{
	// �ؽ� ���̺� ��ü
	HashTable table;

	table.Add("Park", "Yujin");
	table.Add("Shin", "Jiryeong");
	table.Add("An", "Hongjun");
	table.Add("Shin", "Jiryeong");

	table.Print();

	Pair<std::string, std::string> value;
	if (table.Find("Shin", value))
	{
		std::cout << "Ű: Shin �׸��� ã�ҽ��ϴ�.\n";
	}
	else
	{
		std::cout << "Ű: Shin �׸��� �� ã�ҽ��ϴ�.\n";
	}

	table.Delete("Shin");
	
	std::cout << "===== ���� �� ��� =====\n";
	table.Print();
}
