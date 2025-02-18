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
	DestroyRecursive(root);
	delete nil;
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

void RedBlackTree::Print(int depth, int blackCount)
{
	PrintRecursive(root, depth, blackCount);
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
	Insert(CreateNode(data, Color::Red));
	return true;
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

void RedBlackTree::RestructureAfterRemove(Node* node)
{
	// ���� �� ���� �ذ�
	while (node->Parent() != nullptr && node->GetColor() == Color::Black)
	{
		// ���� ��� ���ϱ�
		if (node == node->Parent()->Left())
		{
			Node* sibling = node->Parent()->Right();
			if (sibling == nil)
			{
				break;
			}

			// Case 1: ���� ��尡 �������� ���
			// �ذ�: ���� ��带 Black���� �����ϰ�,
			// �θ� Red�� �ٲ� �� �θ� �������� ��ȸ�� �Ǵ� ��ȸ��
			if (sibling->GetColor() == Color::Red)
			{
				sibling->SetColor(Color::Black);
				node->Parent()->SetColor(Color::Red);

				// ��ȸ��.
				RotateToLeft(node->Parent());
				continue;
			}

			// Case 2: ���� ��尡 �������� ���
			// �ذ�: ���� ��带 Red�� �����Ͽ� Black Height�� ���̰�,
			// �θ� ���ο� ���� ���� �� �ٽ� �˻�
			if (sibling->Left()->GetColor() == Color::Black
				&& sibling->Right()->GetColor() == Color::Black)
			{
				sibling->SetColor(Color::Red);
				node = node->Parent();
				continue;
			}

			// Case 3: ���� ��尡 �������̰�, ���� ����� ���� �ڽ��� �������� ���
			// �ذ�: ������ ���� �ڽ��� Black���� ����,
			// ������ Red�� ���� �� ���� ���� ��ȸ��
			if (sibling->Left()->GetColor() == Color::Red)
			{
				sibling->Left()->SetColor(Color::Black);
				sibling->SetColor(Color::Red);

				// ��ȸ��
				RotateToRight(sibling);

				// ȸ�� �� ���� ��ġ ������Ʈ
				sibling = node->Parent()->Right();
			}

			// Case 4: ���� ��尡 �������̰�, ���� ����� ������ �ڽ��� �������� ���
			// �ذ�: ������ �θ�� ���� ������ ����,
			// �θ� Black���� ����,
			// ������ ������ �ڽ��� Black���� ���� �� �θ� ���� ��ȸ��
			if (sibling->Right()->GetColor() == Color::Red)
			{
				sibling->SetColor(sibling->Parent()->GetColor());
				sibling->Parent()->SetColor(Color::Black);
				sibling->Right()->SetColor(Color::Black);
				RotateToLeft(node->Parent());
			}

			continue;
		}

		// ���� ��� ���ϱ�
		if (node == node->Parent()->Right())
		{
			Node* sibling = node->Parent()->Left();
			if (sibling == nil)
			{
				break;
			}

			// Case 1: ���� ��尡 �������� ���
			// �ذ�: ���� ��带 Black���� �����ϰ�,
			// �θ� Red�� �ٲ� �� �θ� �������� ��ȸ�� �Ǵ� ��ȸ��
			if (sibling->GetColor() == Color::Red)
			{
				sibling->SetColor(Color::Black);
				node->Parent()->SetColor(Color::Red);

				// ��ȸ��.
				RotateToRight(node->Parent());
				continue;
			}

			// Case 2: ���� ��尡 �������� ���
			// �ذ�: ���� ��带 Red�� �����Ͽ� Black Height�� ���̰�,
			// �θ� ���ο� ���� ���� �� �ٽ� �˻�
			if (sibling->Left()->GetColor() == Color::Black
				&& sibling->Right()->GetColor() == Color::Black)
			{
				sibling->SetColor(Color::Red);
				node = node->Parent();
				continue;
			}

			// Case 3: ���� ��尡 �������̰�, ���� ����� ���� �ڽ��� �������� ���
			// �ذ�: ������ ������ �ڽ��� Black���� ����,
			// ������ Red�� ���� �� ���� ���� ��ȸ��
			if (sibling->Right()->GetColor() == Color::Red)
			{
				sibling->Right()->SetColor(Color::Black);
				sibling->SetColor(Color::Red);

				// ��ȸ��
				RotateToLeft(sibling);

				// ȸ�� �� ���� ��ġ ������Ʈ
				sibling = node->Parent()->Left();
			}

			// Case4: ���� ���� �������̰�, ������ ���� �ڽ��� �������� ���
			// �ذ�: ������ �θ�� ���� ������ ����,
			// �θ� Black���� ����,
			// ������ ���� �ڽ��� Black���� ���� �� �θ� ���� ��ȸ��
			if (sibling->Left()->GetColor() == Color::Red)
			{
				sibling->SetColor(sibling->Parent()->GetColor());
				sibling->Parent()->SetColor(Color::Black);
				sibling->Left()->SetColor(Color::Black);
				RotateToRight(node->Parent());
			}
		}

		// ��Ʈ ���� ������
		root->SetColor(Color::Black);
	}
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

Node* RedBlackTree::FindMinRecursive(Node* node)
{
	// Ż�� ����
	if (node == nil)
	{
		return nullptr;
	}

	// ���� ���� ��尡 �� �̻� ������ ���� ��� ��ȯ
	if (node->Left() == nil)
	{
		return node;
	}

	return FindMinRecursive(node->Left());
}

Node* RedBlackTree::FindMaxRecursive(Node* node)
{
	// Ż�� ����
	if (node == nil)
	{
		return nullptr;
	}

	// ������ ���� ��尡 �� �̻� ������ ���� ��� ��ȯ
	if (node->Right() == nil)
	{
		return node;
	}

	return FindMaxRecursive(node->Right());
}

void RedBlackTree::Remove(int data)
{
	// ������ ��� �˻��� �����ϸ� ���� ����
	Node* deleted = nullptr;
	if (!Find(data, &deleted))
	{
		std::cout
			<< "����: ��� ���� ����. ������ ��带 ã�� ���߽��ϴ� (�˻� ��: "
			<< data << ").\n";
		return;
	}

	// ���� ����
	RemoveImpl(deleted);
}

void RedBlackTree::RemoveImpl(Node* node)
{
	// ���� ��� ���
	Node* removed = nullptr;

	// ������ ��ġ�� ��ü ���
	Node* trail = nil;

	Node* target = node;

	// �ڼ��� �ϳ� ������ ���
	if (target->Left() == nil || target->Right() == nil)
	{
		removed = target;
	}
	// �ڼ��� ��� �ִ� ���
	else
	{
		// ��ü�� ��� �˻�
		// (���� ���� Ʈ������ ���� ū ���� ��ü ���� ����)
		removed = FindMaxRecursive(target->Left());

		// ���� ����� ���� ��� ����� ������ ����
		target->SetData(removed->Data());
	}

	// �ڼ��� �ϳ��� �ִ� ���
	if (node->Left() != nil && node->Right() == nil)
	{
		trail = node->Left();
	}
	else if (node->Right() != nil && node->Left() == nil)
	{
		trail = node->Right();
	}

	// ��� ��尡 �ִ� ���.
	if (trail != nil)
	{
		trail->SetParent(removed->Parent());
	}

	// removed ��尡 root�� ���
	if (removed->Parent() == nullptr)
	{
		root = trail;
	}
	// root�� �ƴ� ���
	else
	{
		// trail ��带 removed�� ���� ��ġ�� ����
		if (removed == removed->Parent()->Left())
		{
			removed->Parent()->SetLeft(trail);
		}
		else
		{
			removed->Parent()->SetRight(trail);
		}
	}

	// ������ ���� Ȯ�� �� ����
	if (removed->GetColor() == Color::Black && trail != nil)
	{
		// ������ ����
	}

	// ��� ����
	SafeDelete(removed);
}

void RedBlackTree::DestroyRecursive(Node* node)
{
	// ��� Ż�� ����
	if (node == nil)
	{
		return;
	}

	// �ڽ��� �ִ� ���
	DestroyRecursive(node->Left());
	DestroyRecursive(node->Right());

	// ��� ����
	SafeDelete(node);
}

void RedBlackTree::PrintRecursive(Node* node, int depth, int blackCount)
{
	// Ż�� ����
	if (node == nil)
	{
		return;
	}

	// ��尡 ������ �����̸� blackCount ����
	if (node->GetColor() == Color::Black)
	{
		++blackCount;
	}

	// �θ� ǥ�� ���ڿ� ����
	int parentData = 0;
	const char* position = "Root";

	// �θ� ��尡 �ִ��� Ȯ��
	if (node->Parent())
	{
		// �θ� ����� ������ ����
		parentData = node->Parent()->Data();

		// �θ� ���κ��� ���� ����� ��ġ ����
		if (node == node->Parent()->Left())
		{
			position = "Left";
		}
		else
		{
			position = "Right";
		}
	}

	// ������ �� ����� ���� ���ڿ�
	char blackCountString[50] = { };

	// �ڼ��� ������ ��������� ������ ��� �� ����
	if (node->Left() == nil && node->Right() == nil)
	{
		sprintf_s(blackCountString, "------ %d", blackCount);
	}

	// Depth ���
	for (int ix = 0; ix < depth; ++ix)
	{
		std::cout << "  ";
	}

	// ��� ���� ���� �ܼ� ����
	if (node->GetColor() == Color::Red)
	{
		SetTextColor(TextColor::Red);
	}
	else
	{
		SetTextColor(TextColor::White);
	}

	// ���� ��� �� ���
	std::cout
		<< node->Data() << " "
		<< node->ColorString() << " ["
		<< position << ", "
		<< parentData << "] "
		<< blackCountString << "\n";

	// ��带 ����� �ڿ��� �ܼ� ����
	SetTextColor(TextColor::White);

	// ���� ���
	PrintRecursive(node->Left(), depth + 1, blackCount);
	PrintRecursive(node->Right(), depth + 1, blackCount);
}

void SetTextColor(TextColor color)
{
	static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)color);
}
