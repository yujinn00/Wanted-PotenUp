#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����
class Node
{
	// std::cout�� ���� ����� �� �ֵ��� �����ε�
	friend std::ostream& operator<<(std::ostream& os, const Node& node);

	// ����
	friend class LinkedList;

public:
	// ������
	Node();
	Node(int data);

private:
	// ������ �ʵ�
	int data = 0;

	// ��ũ �ʵ�
	Node* next = nullptr;
};
