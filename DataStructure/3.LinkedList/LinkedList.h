#pragma once

#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// ��忡 �߰��ϴ� �Լ�
	void AddToHead(int data);

	// �����͸� �����ϴ� �Լ�
	void Insert(int data);

	// �����͸� ������ �˻� �� �����ϴ� �Լ�
	void Delete(int data);

	// ����� ��Ҹ� ����ϴ� �Լ�
	void Print();

	// ����� ����� ���� ��ȯ�ϴ� �Լ� (Getter)
	__forceinline int Count() const;

private:
	// ��� ��� = ���� ���
	Node* head = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int count = 0;
};
