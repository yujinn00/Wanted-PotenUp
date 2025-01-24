#pragma once

// ��� Ŭ����
template<typename T>
class Node
{
	// ���� Ž�� Ʈ���� ������� ����
	template<typename T>
	friend class BinarySearchTree;

public:
	Node(const T& data)
		: data(data), parent(nullptr), left(nullptr), right(nullptr)
	{
	}

	Node(const T& data, Node<T>* parent)
		: data(data), parent(parent), left(nullptr), right(nullptr)
	{
	}

	~Node()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

private:
	// ����
	T data;

	// �θ� ���
	Node<T>* parent;

	// ���� �ڼ�
	Node<T>* left;

	// ������ �ڼ�
	Node<T>* right;

};
