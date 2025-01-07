#pragma once

#include "Node.h"

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
template<typename T>
class LinkedList
{
public:
	// ������ �߻����� �� ������ �Լ��� �����ϴ� �Լ� ������ ����
	using ListEmptyErrorEvent = void (*)();

	//// �� �Լ� Ÿ�� ����
	//using Comparer = bool (*)(T& left, T& right)

public:
	LinkedList()
		: first(new Node<T>()), last(new Node<T>())
	{
		// ������ ���� first�� last�� ���θ� ����Ű���� ����
		first->next = last;
		last->previous = first;
	}

	LinkedList(ListEmptyErrorEvent errorHandler)
		: LinkedList<T>()
	{
		errorEvent = errorHandler;
	}

	~LinkedList()
	{
		if (count > 0)
		{
			Clear();
		}

		delete first;
		delete last;
	}

	// ����Ʈ �ȿ� ��� ��带 �����ϴ� �Լ�
	void Clear()
	{
		// ����Ʈ�� ������� ���� �߻�
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
		}

		// ù ������ ����
		Node<T>* current = first->next;

		while (current != nullptr && current != last)
		{
			// ���� ����
			Node<T>* next = current->next;
			delete current;
			current = next;
		}

		// ���� ������ ����
		count = 0;
		first->next = last;
		last->previous = first;
	}

	// ����Ʈ�� ����� �� ���� �̺�Ʈ�� �߻���Ű�� �Լ�
	// Invoke: ���� ȣ��
	void RaiseEmptyErrorEvent()
	{
		// �Լ� �����Ͱ� �����Ǿ����� �ش� �Լ� ȣ��
		if (errorEvent != nullptr)
		{
			errorEvent();
		}
	}

	// ��忡 �߰��ϴ� �Լ�
	void AddToFirst(const T& data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(data);

		// �� ����� ���� ��带 first->next ���� ����
		// �� ����� ���� ��带 first�� ����
		Node<T>* next = first->next;
		newNode->next = next;
		newNode->previous = first;

		// ù ��带 �� ���� ����
		// ���� ù ����� ���� ��带 �� ���� ����
		first->next = newNode;
		next->previous = newNode;

		// ����� ��� �� ���� ó��
		++count;
	}

	// ������ �����ϴ� �Լ�
	void AddToLast(const T& data)
	{
		// �� ��� ����
		Node<T>* newNode = new Node<T>(data);

		Node<T>* previous = last->previous;
		newNode->previous = previous;
		newNode->next = last;

		previous->next = newNode;
		last->previous = newNode;

		// ����� ��� �� ���� ó��
		++count;
	}

	// �����͸� ������ �˻� �� �����ϴ� �Լ�
	void Delete(const T& data)
	{
		// ���� ó��
		if (count == 0)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ������ ��� �˻�
		Node<T>* deleteNode = first->next;
		while (deleteNode != nullptr && deleteNode != last)
		{
			if (deleteNode->data == data)
			{
				break;
			}

			// ���� ���� �̵� (�˻� ��� ����)
			deleteNode = deleteNode->next;
		}

		// ���� ó��
		if (deleteNode == nullptr || deleteNode == last)
		{
			RaiseEmptyErrorEvent();
			return;
		}

		// ����
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;

		// ��� ����
		delete deleteNode;
		
		// ����� ����� �� ���� ó��
		--count;
	}

	// �����͸� �˻��Ͽ� ��ȯ�ϴ� �Լ�
	Node<T>* Find(const T& data)
	{
		Node<T>* current = first->next;

		while (current != nullptr && current != last)
		{
			if (current->data == data)
			{
				return current;
			}

			current = current->next;
		}

		return nullptr;
	}

	//Node<T>* FindReverse(const T& data)
	//{
	//}

	// ����� ��Ҹ� ����ϴ� �Լ�
	void Print()
	{
		Node<T>* current = first->next;
		while (current != nullptr && current != last)
		{
			std::cout << "Data: " << current->data << "\n";
			current = current->next;
		}
	}

	// ����� ����� ���� ��ȯ�ϴ� �Լ� (Getter)
	__forceinline int Count() const
	{
		return count;
	}

private:
	// ��� ��� = ���� ���
	Node<T>* first = nullptr;

	// ���� ��� = ������ ���
	Node<T>* last = nullptr;

	// ����� �ڷ� ���� ��Ÿ���� ����
	int count = 0;

	// �Լ� ������ ����
	ListEmptyErrorEvent errorEvent = nullptr;
};
