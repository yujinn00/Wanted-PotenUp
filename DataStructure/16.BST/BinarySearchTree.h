#pragma once

#include <iostream>
#include "Node.h"

// ���� Ž�� Ʈ�� Ŭ����
template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree()
		: root(nullptr)
	{
	}

	~BinarySearchTree()
	{
		// ��� ���� �Լ� ȣ��
		Destroy();
	}

	// �˻�
	bool SearchNode(const T& data)
	{
		// ��Ʈ���� ��������� �˻�
		return searchNodeRecursive(root, data);
	}

	// ����
	// 0. �ߺ��� ���� ������� �ʴ´�.
	// 1. ��Ʈ�������� �񱳸� �����Ѵ�.
	// 1-1. ��Ʈ�� ��� ������ �� ��带 ��Ʈ�� �����Ѵ�.
	// 2. ���� �߰��ϴ� ���� ���ϴ� ��庸�� ������ ���� ���� Ʈ���� �񱳸� �̾��.
	// 3. ���� �߰��ϴ� ���� ���ϴ� ��庸�� ũ�� ������ ���� Ʈ���� �񱳸� �̾��.
	bool InsertNode(const T& newData)
	{
		// �ߺ��� ������� �ʱ� ������ �̹� ������ ����
		if (SearchNode(newData))
		{
			// ���� �޼��� ���
			std::cout << "Error: �̹� �ߺ��� ���� �־� �߰� �Ұ���.\n";
			return false;
		}

		// Case 1: ��Ʈ�� �� ���
		if (root == nullptr)
		{
			// ��Ʈ ���� �� ����
			root = new Node<T>(newData);
			return true;
		}

		// Case 2, 3: ��� �Լ��� ó��
		root = InsertNodeRecursive(root, nullptr, newData);
		return true;
	}

	// ����
	bool DeleteNode(const T& deleteNode)
	{
		// ������ ��尡 ������ ����
		if (!SearchNode(deleteNode))
		{
			return false;
		}

		// ��������� �˻��� �����ϴ� �Լ� ȣ��
		root = DeleteNodeRecursive(root, deleteNode);
		return true;
	}

	// ���� ��ȸ
	void InorderTraverse(int depth = 0)
	{
		std::cout << "===== ���� ��ȸ ���� =====\n";

		// ��� �Լ� ȣ��
		InorderTraverseRecursive(root);

		std::cout << "===== ���� ��ȸ ���� =====\n";
	}

private:
	// ��� ��带 ������ �� ����ϴ� �Լ�
	void Destroy()
	{
		// ��Ʈ ��尡 null�̸� ����
		if (root == nullptr)
		{
			return;
		}

		// ���� �ڼ� > ������ �ڼ� > ��Ʈ ������ ����
		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* node)
	{
		// ����Լ� ���� ����
		if (node == nullptr)
		{
			return;
		}

		// ���� �ڼ� / ������ �ڼ� Ȯ��
		Node<T>* left = node->left;
		Node<T>* right = node->right;

		// �ڼ��� ���� ���
		if (left == nullptr && right == nullptr)
		{
			// ��� ���� �� �Լ� ����
			delete node;
			return;
		}

		DestroyRecursive(left);
		DestroyRecursive(right);

		delete node;
	}

	// node: ���� �湮�Ϸ��� ���
	// depth: ��¿� ����� ���� ��
	void InorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����
		if (node == nullptr)
		{
			// ���� ���
			for (int i = 0; i < depth; ++i)
			{
				// �� ĭ ����
				std::cout << "  ";
			}

			std::cout << "null\n";
			return;
		}

		// ���� ���� Ʈ�� �湮
		InorderTraverseRecursive(node->left, depth + 1);

		// ���� ���
		for (int i = 0; i < depth; ++i)
		{
			// �� ĭ ����
			std::cout << "  ";
		}

		// �θ� ��� �湮
		std::cout << node->data << "\n";

		// ������ ���� Ʈ�� �湮
		InorderTraverseRecursive(node->right, depth + 1);
	}

	// node: ���� �˻� ��� ���
	// deleteNode: ������ ������
	Node<T>* DeleteNodeRecursive(Node<T>* node, const T& deleteData)
	{
		// ���� ����
		if (node == nullptr)
		{
			return nullptr;
		}

		// ���� ���
		if (node->data > deleteData)
		{
			node->left = DeleteNodeRecursive(node->left, deleteData);
		}

		// ū ���
		else if (node->data < deleteData)
		{
			node->right = DeleteNodeRecursive(node->right, deleteData);
		}

		// ������ ��带 ã�� ���
		else
		{
			// Case 1: �ڽ��� ���� ���
			if (node->left == nullptr && node->right == nullptr)
			{
				// ��� ���� �� ����
				delete node;
				return nullptr;
			}

			// Case 2: �ڽ��� ���� ���
			if (node->left != nullptr && node->right != nullptr)
			{
				// ���ʿ��� �ִ� �Ǵ� �����ʿ��� �ּڰ� ��� ã��
				node->data = SearchMinValue(node->right)->data;

				// ������ ���� ������ ���� Ʈ������ ���� ���� ���� ���� ��带 ����
				node->right = DeleteNodeRecursive(node->right, node->data);
			}

			// Case 3: �ڽ��� �ϳ��� ���
			else
			{
				// ���� �ڽĸ� �ִ� ���
				if (node->left != nullptr)
				{
					// �ӽ� ����
					Node<T>* left = node->left;

					// ����
					delete node;

					// ���� �ڼ� ��ȯ
					return left;
				}

				// ������ �ڽĸ� �ִ� ���
				else if (node->right != nullptr)
				{
					// �ӽ� ����
					Node<T>* right = node->right;

					// ����
					delete node;

					// ������ �ڼ� ��ȯ
					return right;
				}
			}
		}

		return node;
	}

	// �ּڰ��� �˻��ϴ� �Լ�
	// node: �˻��� �����ϴ� ���
	Node<T>* SearchMinValue(Node<T>* node)
	{
		// ���� ��尡 ���� ������ ã�� �� ��ȯ
		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}

	// ��������� Ÿ�� �����͸� �˻��ϴ� �Լ�
	bool searchNodeRecursive(Node<T>* node, const T& data)
	{
		// �˻� ����
		if (node == nullptr)
		{
			return false;
		}

		// �˻� ����
		if (node->data == data) {
			return true;
		}

		// ������ ��������, ũ�� ���������� �˻�
		if (node->data > data)
		{
			return searchNodeRecursive(node->left, data);
		}
		else
		{
			return searchNodeRecursive(node->right, data);
		}
	}

	// node: ���� ���ϴ� ���
	// parent: node�� �θ� ���
	// newData: �����Ϸ��� ������
	Node<T>* InsertNodeRecursive(Node<T>* node, Node<T>* parent, const T& newData)
	{
		// node�� null�̸� �߰�
		if (node == nullptr)
		{
			// �� ��� ���� �� ��ȯ
			return new Node<T>(newData, parent);
		}

		// �߰��Ϸ��� ���� �� ��庸�� ������, ���� ���� Ʈ���� Ž��
		if (node->data > newData)
		{
			node->left = InsertNodeRecursive(node->left, node, newData);
		}

		// �߰��Ϸ��� ���� �� ��庸�� ũ��, ������ ���� Ʈ���� Ž��
		else
		{
			node->right = InsertNodeRecursive(node->right, node, newData);
		}

		return node;
	}

private:
	// ��Ʈ ���
	Node<T>* root;
};
