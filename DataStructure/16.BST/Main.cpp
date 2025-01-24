#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	// ���� Ž�� Ʈ�� ����
	BinarySearchTree<int> tree;

	// ��� �߰�
	tree.InsertNode(50);
	tree.InsertNode(20);
	tree.InsertNode(100);
	tree.InsertNode(70);
	tree.InsertNode(80);
	tree.InsertNode(30);

	// ��� �˻�
	int searchData = 120;
	if (tree.SearchNode(searchData))
	{
		std::cout << searchData << " �˻� ����\n";
	}
	else
	{
		std::cout << searchData << " �˻� ����\n";
	}

	// ��� ����
	int deleteNode = 120;
	if (tree.DeleteNode(deleteNode))
	{
		std::cout << deleteNode << " ���� ����\n";
	}
	else
	{
		std::cout << deleteNode << " ���� ����\n";
	}

	tree.InorderTraverse();
}
