#pragma once

#include "Node.h"

template<typename T>
class BinaryTree
{
public:
	// ������
	BinaryTree(const T& data)
	{
		root = new Node<T>(data);
	}

	// �Ҹ���
	~BinaryTree()
	{
		// ��� ��� ����
		root->Destroy();
	}

	void AddLeftChild(const T& parentData, const T& childData)
	{
		// �θ� ��� �˻�
		Node<T>* outParent = nullptr;
		if (Find(parentData, &outParent))
		{
			outParent->AddLeftChild(childData);
			return;
		}

		// �˻� �����ϸ� �޼��� ���
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰��� �����߽��ϴ�.\n";
	}

	void AddRightChild(const T& parentData, const T& childData)
	{
		// �θ� ��� �˻�
		Node<T>* outParent = nullptr;
		if (Find(parentData, &outParent))
		{
			outParent->AddRightChild(childData);
			return;
		}

		// �˻� �����ϸ� �޼��� ���
		std::cout << "Error: �θ� ��带 ã�� ���� �ڼ� ��� �߰��� �����߽��ϴ�.\n";
	}

	// ���� ������� ��带 �˻��ϴ� �Լ�
	bool Find(const T& data, Node<T>** outNode)
	{
		return FindRecursive(data, root, outNode);
	}

	// �����͸� ������� ��带 �����ϴ� �Լ�
	bool DeleteNode(const T& data)
	{
		// ���� ��� �˻�
		Node<T>* outNode = nullptr;
		if (Find(data, &outNode))
		{
			// �˻��� ��� ����
			outNode->Destroy();
			return true;
		}

		// �˻��� ���������� �޼��� ���
		std::cout << "������ ��� �˻��� �����߽��ϴ�.\n";
		false;
	}

	// ���� ��ȸ �Լ�
	void PreorderTraverse(int depth = 0)
	{
		std::cout << "���� ��ȸ ���� ----------\n";
		PreorderTraverseRecursive(root, depth);
		std::cout << "���� ��ȸ �� ----------\n";
	}

private:
	// ���� ��ȸ ��� �Լ�
	void PreorderTraverseRecursive(Node<T>* node, int depth)
	{
		// Ż�� ����
		if (node == nullptr)
		{
			return;
		}

		// �X�� ���
		for (int ix = 0; ix < depth; ++ix)
		{
			std::cout << " ";
		}

		// �θ� ��� ���
		std::cout << node->data << "\n";

		// ���� ���� ��� ���
		PreorderTraverseRecursive(node->left, depth + 1);

		// ������ ���� ��� ���
		PreorderTraverseRecursive(node->right, depth + 1);
	}

	// �˻� ��� �Լ�
	bool FindRecursive(const T& data, Node<T>* node, Node<T>** outNode)
	{
		// Ż�� ����
		if (node == nullptr)
		{
			*outNode = nullptr;
			return false;
		}

		// ���� ��忡�� �˻�
		if (node->data == data)
		{
			*outNode = node;
			return true;
		}

		// ���� ������ ������ �˻�
		if (FindRecursive(data, node->left, outNode))
		{
			return true;
		}

		// ���� ������ ������ �˻�
		if (FindRecursive(data, node->right, outNode))
		{
			return true;
		}

		// �˻� ����
		*outNode = nullptr;
		return false;
	}

private:
	// ��Ʈ ���
	Node<T>* root = nullptr;
};
