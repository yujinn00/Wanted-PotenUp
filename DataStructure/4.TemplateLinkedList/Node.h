#pragma once

#include <iostream>

// ��ũ�� ����Ʈ�� ����� ��� Ŭ����
template<typename T>
class Node
{
	// ����
	template<typename T>
	friend class LinkedList;

public:
	// ������
	Node()
		: data() // ��ĭ���� ��ġ�ϸ� Ÿ�Կ� �°� ����Ʈ�� ����
	{
	}

	Node(T data)
		: data(data)
	{
	}

private:
	// ������ �ʵ�
	T data;

	// ��ũ �ʵ�
	Node<T>* next = nullptr;
};
