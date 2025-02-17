#pragma once

#include "Node.h"

#include <iostream>
#include <string>

// ���� �� Ʈ�� Ŭ����
class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();

	// ��� �˻� �Լ�
	bool Find(int data, Node** outNode);

	// ��� �߰� �Լ�
	bool Insert(int data);

private:
	// ��� ���� �Լ�
	Node* CreateNode(int data, Color color);

	// ��� �˻� ��� �Լ�
	bool FindRecursive(Node* node, Node** outNode, int data);

	// ��� �߰� �Լ� (�� ��� ����)
	void Insert(Node* newNode);

	// Ʈ���� ��带 �߰��ϴ� ��� �Լ�
	void InsertRecursive(Node* node, Node* newNode);

	// ��� ���� �� �������� ó���ϴ� �Լ�
	void RestructureAfterInsert(Node* newNode);

	// ��ȸ�� �Լ�
	// node: ȸ���� ������ (�ǹ�)
	void RotateToLeft(Node* node);

	// ��ȸ�� �Լ�
	// node: ȸ���� ������ (�ǹ�)
	void RotateToRight(Node* node);

private:
	// ��Ʈ ���
	Node* root = nullptr;

	// Nil ���
	static Node* nil;
};
