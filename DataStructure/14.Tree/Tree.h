#pragma once

#include "List.h"
#include "Node.h"

template<typename T>
class Tree
{
public:
	// ������
	Tree(const T& data)
	{
		// ��Ʈ ��� ����
		root = new Node<T>(data);
	}

	// �Ҹ���
	~Tree()
	{
		// ��������� �ڼ� ��� ����
		DestroyRecursive(root);
	}

	// �θ� ��� ���� ����� �ڼ��� �߰��ϴ� �Լ�
	void AddChild(const T& parentData, const T& childData)
	{
		// �θ� ��� �˻�
		Node<T>* parent = nullptr;
		if (FindRecursive(parentData, root, &parent))
		{
			parent->AddChild(childData);
			return;
		}

		std::cout << "�ش� ���� ã�� �θ� ��尡 ���� �߰��� �����߽��ϴ�.\n";
	}

	// �ڼ� �߰�
	void AddChild(Node<T>* child, Node<T>* parent = nullptr)
	{
		child->parent = parent == nullptr ? root : parent;
		child->parent->AddChild(child);
	}

	void AddChild(const T& data, Node<T>* parent = nullptr)
	{
		AddChild(new Node<T>(data), parent);
	}

	// ��带 �����ϴ� �Լ�
	bool Remove(const T& data)
	{
		// ��������� �����ϴ� �Լ� �߰� �� ȣ��
		return RemoveRecursive(data, root);
	}

	// ��� �˻� �Լ�
	bool Find(const T& data, Node<T>** outNode)
	{
		// ��� �˻� �Լ� ȣ�� �� ��� ��ȯ
		return FindRecursive(data, root, outNode);
	}

	// ���� ��ȸ (�θ� -> �ڼ�)
	void PreorderTraverse(int depth = 0)
	{
		PreorderTraverseRecursive(root, depth);
	}

private:
	// ���� ��ȸ ��� �Լ�
	void PreorderTraverseRecursive(Node<T>* node, int depth = 0)
	{
		// ���� ����
		if (node == nullptr)
		{
			return;
		}

		// ���� ���
		for (int i = 0; i < depth; ++i)
		{
			std::cout << "  ";
		}

		// �θ� ���
		std::cout << node->data << "\n";

		// �ڼ� ��� ���
		List<Node<T>*>* children = node->children;
		if (children->Size() == 0)
		{
			return;
		}

		for (int i = 0; i < children->Size(); ++i)
		{
			Node<T>* child = children->At(i);
			PreorderTraverseRecursive(child, depth + 1);
		}
	}

	// ��� ���� ��� �Լ�
	bool RemoveRecursive(const T& data, Node<T>* node)
	{
		// ������ ��� �˻�
		Node<T>* outNode = nullptr;
		if (FindRecursive(data, node, outNode))
		{
			// �˻� ����
			
			// �θ� ����� �ڼ� ��Ͽ��� ����
			Node<T>* parent = outNode->parent;
			if (parent != nullptr)
			{
				parent->children->Remove(outNode);
			}

			// ������ �ڼ��� �ִ� ��쿡�� �ڼ� ����
			List<Node<T>*>* children = outNode->children;
			while (children != nullptr && children->Size() > 0)
			{
				outNode->RemoveChild(children->At(0));
			}

			// �޸� ����
			delete outNode;
			outNode = nullptr;

			// ���� ����
			return true;
		}
	}

	// �ڼ� ��带 ������ ��� ��带 ��������� �����ϴ� �Լ�
	void DestroyRecursive(Node<T>* node)
	{
		// �ڼ� ����Ʈ Ȯ�� �� ��������� ���� ����
		List<Node<T>*>* children = node->children;
		while (children != nullptr && children->Size() > 0)
		{
			Node<T>* child = children->At(0);
			DestroyRecursive(child);
		}

		// �θ� ��尡 ������ �θ��� �ڼ� ��Ͽ��� �ڽ� ����
		Node<T>* parent = node->parent;
		if (parent != nullptr)
		{
			parent->children->Remove(node);
		}

		// ����
		delete node;
		node = nullptr;
	}

	// ��������� �˻��ϴ� �Լ�
	// data: �˻��� ����� �� (�� ���� ���� ��带 �˻�)
	// node: �˻� ��ġ
	// outNode: �˻��� �������� �� ��ȯ�� �Ķ����
	bool FindRecursive(const T& data, Node<T>* node, Node<T>** outNode)
	{
		// ���� ó��
		if (node == nullptr)
		{
			*outNode = nullptr;
			return false;
		}

		// ��� �˻��� ������ ���
		if (node->data == data)
		{
			*outNode = node;
			return true;
		}

		// ��������� �ڼ� ��� �˻� ����
		List<Node<T>*>* children = node->children;
		int size = children->Size();
		for (int i = 0; i < size; ++i)
		{
			// �ڼ� ��� �˻�
			Node<T>* child = children->At(i);
			bool result = FindRecursive(data, child, outNode);

			// �˻��� ���������� ����
			if (result)
			{
				return true;
			}
		}

		// �˻� ����
		*outNode = nullptr;
		return false;
	}

private:
	// ��Ʈ ���
	Node<T>* root = nullptr;
};
