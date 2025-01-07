#pragma once

#include <iostream>

// 링크드 리스트의 요소인 노드 클래스
template<typename T>
class Node
{
	// 예외
	template<typename T>
	friend class LinkedList;

public:
	// 생성자
	Node()
		: data() // 빈칸으로 배치하면 타입에 맞게 디폴트를 설정
	{
	}

	Node(T data)
		: data(data)
	{
	}

private:
	// 데이터 필드
	T data;

	// 링크 필드
	Node<T>* next = nullptr;
};
