#include <iostream>

#include "LinkedList.h"

// ���� �Լ�
// �̺�Ʈ ������ �Լ�
void OnListEmptyError()
{
	std::cout << "�����Ͱ� �����ϴ�.\n";
}

int main()
{
	LinkedList<int> list(OnListEmptyError);
	list.Delete(100);

	list.AddToFirst(50);
	list.AddToFirst(40);
	list.AddToFirst(30);
	list.AddToFirst(20);
	list.AddToFirst(10);

	std::cout << "----- ����Ʈ ��� -----\n";
	list.Print();

	list.AddToLast(60);
	list.AddToLast(70);
	list.AddToLast(80);
	list.AddToLast(90);
	list.AddToLast(100);

	std::cout << "----- ����Ʈ ��� -----\n";
	list.Print();

	list.Delete(20);
	list.Delete(40);
	list.Delete(60);
	list.Delete(80);
	list.Delete(100);

	std::cout << "----- ����Ʈ ��� -----\n";
	list.Print();
}
