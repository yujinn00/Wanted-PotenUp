#pragma once

#include "Node.h"

// 노드를 사용해 자료를 저장하는 링크드 리스트
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	// 헤드에 추가하는 함수
	void AddToHead(int data);

	// 데이터를 삽입하는 함수
	void Insert(int data);

	// 데이터를 지정해 검색 후 삭제하는 함수
	void Delete(int data);

	// 저장된 요소를 출력하는 함수
	void Print();

	// 저장된 요소의 수를 반환하는 함수 (Getter)
	__forceinline int Count() const;

private:
	// 헤드 노드 = 시작 노드
	Node* head = nullptr;

	// 저장된 자료 수를 나타내는 변수
	int count = 0;
};
