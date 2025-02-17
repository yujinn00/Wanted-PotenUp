#include "RedBlackTree.h"

Node* RedBlackTree::nil = nullptr;

Node* RedBlackTree::CreateNode(int data, Color color)
{
	Node* newNode = new Node(data, color);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	return newNode;
}

RedBlackTree::RedBlackTree()
{
	// �ʱ� ����
	if (nil == nullptr)
	{
		nil = new Node(0, Color::Black);
	}

	root = nil;
}

RedBlackTree::~RedBlackTree()
{
	// @Todo: ��� ��� ����
}

bool RedBlackTree::Find(int data, Node** outNode)
{
	// Ʈ���� ����ٸ�, �˻� ����
	if (root == nil)
	{
		return false;
	}

	// ��������� �˻� ����
	return FindRecursive(root, outNode, data);
}

bool RedBlackTree::Insert(int data)
{
	// ���� �ߺ��Ǵ� �����Ͱ� �ִ��� Ȯ��
	Node* node = nullptr;
	if (Find(data, &node))
	{
		std::cout << "���� - ��� �߰� ����: �̹� ���� ���� �ֽ��ϴ�. �Է� ��: " << data << "\n";
		return false;
	}

	// ��� ���� �� ��� ��ȯ
	return Insert(CreateNode(data, Color::Red));
}

bool RedBlackTree::FindRecursive(Node* node, Node** outNode, int data)
{
	// ��� Ż�� ���� (�˻� ����)
	if (node == nil)
	{
		return false;
	}

	// �˻��� ���������� true �� outNode ��ȯ
	if (node->Data() == data)
	{
		*outNode = node;
		return true;
	}

	// �˻��� �����Ͱ� ���� ��� ������ ������ �������� �˻� ����
	if (node->Data() > data)
	{
		return FindRecursive(node->Left(), outNode, data);
	}
	else
	{
		return FindRecursive(node->Right(), outNode, data);
	}
}

void RedBlackTree::Insert(Node* newNode)
{
	// Ʈ���� ��� �ִ� ���, ��Ʈ�� ����
	if (root == nil)
	{
		root = newNode;
		root->SetColor(Color::Black);
		return;
	}

	// Ʈ���� ��� ���� ������, ��������� ��ġ �˻� �� ����
	InsertRecursive(root, newNode);

	// ���Ե� ��� �� ����
	newNode->SetColor(Color::Red);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	// ���� �� ������ ó��
	RestructureAfterInsert(newNode);
}

void RedBlackTree::InsertRecursive(Node* node, Node* newNode)
{
	// �� ����� �����Ͱ� ���� ��庸�� ������, ���� ���� Ʈ���� ���� ����
	if (node->Data() > newNode->Data())
	{
		// ���� �ڼ��� ���ٸ�, ���� ó��
		if (node->Left() == nil)
		{
			node->SetLeft(newNode);
			newNode->SetParent(node);
			return;
		}

		// �ڼ��� ������, ���� Ʈ���� ���� ���� ����
		InsertRecursive(node->Left(), newNode);
	}
	else
	{
		// ������ �ڼ��� ���ٸ�, ����
		if (node->Right() == nil)
		{
			node->SetRight(newNode);
			newNode->SetParent(node);
			return;
		}

		// �ڼ��� ������, ���� Ʈ���� ���� ����
		InsertRecursive(node->Right(), newNode);
	}
}

void RedBlackTree::RestructureAfterInsert(Node* newNode)
{
	// �θ� ��尡 �������� ��� (Red-Red Conflict)
	while (newNode != root && newNode->Parent()->GetColor() == Color::Red)
	{
		// ���� ���ϱ� (����)
		if (newNode->Parent() == newNode->Parent()->Parent()->Left())
		{
			// ����
			Node* uncle = newNode->Parent()->Parent()->Right();

			// Case 1: ���� ��尡 �������� ��
			// �ذ�: �θ�� ������ Black, �Ҿƹ����� Red�� ���� ��, �Ҿƹ��� �������� �ٽ� �˻�
			if (uncle->GetColor() == Color::Red)
			{
				newNode->Parent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);
				newNode->Parent()->Parent()->SetColor(Color::Red);

				newNode = newNode->Parent()->Parent();
				continue;
			}

			// ������ �������� ��
			// �ذ�: �θ� Black, �Ҿƹ����� Red�� ���� ��, �Ҿƹ����� �������� ȸ��
			// Case 2: ������� ���� => �θ��� ��ġ�� ���� ��ġ�� �ݴ� (���������� ���� �� Case 3 ó��)
			if (newNode == newNode->Parent()->Right())
			{
				// �θ� �߽����� ȸ�� ó�� (���������� ����� ����)
				newNode = newNode->Parent();
				RotateToLeft(newNode);
			}

			// Case 3: ������ ���� => �θ��� ��ġ�� ���� ��ġ�� ��ġ
			newNode->Parent()->SetColor(Color::Black);
			newNode->Parent()->Parent()->SetColor(Color::Red);

			RotateToRight(newNode->Parent()->Parent());
		}
		// ���� ���ϱ� (������)
		else
		{
			// ����
			Node* uncle = newNode->Parent()->Parent()->Left();

			// Case 1: ���� ��尡 �������� ��
			// �ذ�: �θ�� ������ Black, �Ҿƹ����� Red�� ���� ��, �Ҿƹ��� �������� �ٽ� �˻�
			if (uncle->GetColor() == Color::Red)
			{
				newNode->Parent()->SetColor(Color::Black);
				uncle->SetColor(Color::Black);
				newNode->Parent()->Parent()->SetColor(Color::Red);

				newNode = newNode->Parent()->Parent();
				continue;
			}

			// ������ �������� ��
			// �ذ�: �θ� Black, �Ҿƹ����� Red�� ���� ��, �Ҿƹ����� �������� ȸ��
			// Case 2: ������� ���� => �θ��� ��ġ�� ���� ��ġ�� �ݴ� (���������� ���� �� Case 3 ó��)
			if (newNode == newNode->Parent()->Left())
			{
				// �θ� �߽����� ȸ�� ó�� (���������� ����� ����)
				newNode = newNode->Parent();
				RotateToRight(newNode);
			}

			// Case 3: ������ ���� => �θ��� ��ġ�� ���� ��ġ�� ��ġ
			newNode->Parent()->SetColor(Color::Black);
			newNode->Parent()->Parent()->SetColor(Color::Red);

			RotateToLeft(newNode->Parent()->Parent());
		}
	}

	// ��Ʈ ���� ��
	root->SetColor(Color::Black);
}

void RedBlackTree::RotateToLeft(Node* node)
{
	// ������ �ڽ� ���
	Node* right = node->Right();

	// ������ �ڽ� ����� ���� �ڽ� ��带 �θ��� ������ �ڽ����� ���
	node->SetRight(right->Left());

	// ���� ����� �θ� ó��
	if (right->Left() != nil)
	{
		right->Left()->SetParent(node);
	}

	// ������ �ڽ� ����� �θ� �θ��� �θ�� ����
	right->SetParent(node->Parent());

	// �θ� root�� ���
	if (right->Parent() == nullptr)
	{
		root = right;
	}
	// root�� �ƴ� ��
	else
	{
		// ���θ� ���� ������ �ڽ� ��ġ�� ����
		if (node == node->Parent()->Left())
		{
			node->Parent()->SetLeft(right);
		}
		else
		{
			node->Parent()->SetRight(right);
		}
	}

	// ��ȸ�� ������
	right->SetLeft(node);
	node->SetParent(right);
}

void RedBlackTree::RotateToRight(Node* node)
{
	// ���� �ڽ� ���
	Node* left = node->Left();

	// ���� �ڽ� ����� ������ �ڽ� ��带 �θ��� ���� �ڽ����� ���
	node->SetLeft(left->Right());

	// ���� ����� �θ� ó��
	if (left->Right() != nil)
	{
		left->Right()->SetParent(node);
	}

	// ���� �ڽ� ����� �θ� �θ��� �θ�� ����
	left->SetParent(node->Parent());

	// �θ� root�� ���
	if (left->Parent() == nullptr)
	{
		root = left;
	}
	// root�� �ƴ� ��
	else
	{
		// ���θ� ���� ������ �ڽ� ��ġ�� ����
		if (node == node->Parent()->Right())
		{
			node->Parent()->SetRight(left);
		}
		else
		{
			node->Parent()->SetLeft(left);
		}
	}

	// ��ȸ�� ������
	left->SetRight(node);
	node->SetParent(left);
}
