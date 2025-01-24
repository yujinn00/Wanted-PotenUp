#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	// 이진 탐색 트리 생성
	BinarySearchTree<int> tree;

	// 노드 추가
	tree.InsertNode(50);
	tree.InsertNode(20);
	tree.InsertNode(100);
	tree.InsertNode(70);
	tree.InsertNode(80);
	tree.InsertNode(30);

	// 노드 검색
	int searchData = 120;
	if (tree.SearchNode(searchData))
	{
		std::cout << searchData << " 검색 성공\n";
	}
	else
	{
		std::cout << searchData << " 검색 실패\n";
	}

	// 노드 삭제
	int deleteNode = 120;
	if (tree.DeleteNode(deleteNode))
	{
		std::cout << deleteNode << " 삭제 성공\n";
	}
	else
	{
		std::cout << deleteNode << " 삭제 실패\n";
	}

	tree.InorderTraverse();
}
