#pragma once

#include <iostream>

// ���� Ʈ���� ����� ��� Ŭ����
template<typename T>
class Node
{
	// ���� Ʈ�� Ŭ������ ������� ����
	template<typename T>
	friend class BinaryTree;

public:
	Node()
	{
	}

	Node(const T& data)
		: data(data)
	{
	}

	// ���� �Լ�
	void AddLeftChild(Node<T>* child)
	{
		// 1. ���ο� �ڼ��� �θ� �� ���� ����
		child->parent = this;

		// 2. �� ����� ���� �ڼ��� �� ���� ����
		left = child;
	}

	void AddLeftChild(const T& data)
	{
		AddLeftChild(new Node<T>(data));
	}

	// ���� �Լ�
	void AddRightChild(Node<T>* child)
	{
		// 1. ���ο� �ڼ��� �θ� �� ���� ����
		child->parent = this;

		// 2. �� ����� ������ �ڼ��� �� ���� ����
		right = child;
	}

	void AddRightChild(const T& data)
	{
		AddRightChild(new Node<T>(data));
	}

	// ���� �Լ�
	void Destroy()
	{
		// ����� �θ� �ִ� ��� ���� ����
		if (parent)
		{
			// �� ��尡 �θ��� ���� �ڼ��� ��
			if (parent->left == this)
			{
				parent->left = nullptr;
			}

			// �� ��尡 �θ��� ������ �ڼ��� ��
			if (parent->right == this)
			{
				parent->right = nullptr;
			}
		}

		DestroyRecursive(this);
	}

private:
	// ���� ��� �Լ�
	void DestroyRecursive(Node<T>* node)
	{
		// Ż�� ����
		if (node == nullptr)
		{
			return;
		}

		// �ڼ� ����� ���� Ȯ��
		Node<T>* leftChild = node->left;
		Node<T>* rightChild = node->right;

		// Case 1: �ڼ��� ���� ���
		if (left == nullptr && rightChild == nullptr)
		{
			delete node;
			return;
		}

		// Case 2: ��� �ִ� ���
		// �ڼ� ��� ȣ��
		DestroyRecursive(leftChild);
		DestroyRecursive(rightChild);

		// ����
		delete node;
	}

private:
	// ������
	T data;

	// �θ� ���
	Node<T>* parent = nullptr;

	// ���� �ڼ� ���
	Node<T>* left = nullptr;

	// ������ �ڼ� ���
	Node<T>* right = nullptr;
};
