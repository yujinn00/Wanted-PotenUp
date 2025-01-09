#pragma once

#include <iostream>

// ť�� �ִ� ũ��
const int maxSize = 100;

// ť Ŭ����
class Queue
{
public:
	Queue()
	{
		// �迭�� �ʱ� ���� 0���� ����
		memset(data, 0, sizeof(int) * maxSize);
	}

	// ť�� ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const
	{
		return front == rear;
	}

	// ť�� ���� á���� Ȯ���ϴ� �Լ�
	bool IsFull() const
	{
		return (rear + 1) % maxSize == front;
	}

	// ������ �߰� �Լ�
	void Enqueue(int value)
	{
		if (IsFull())
		{
			std::cout << "Error: ť�� ���� á���ϴ�.\n";
			return;
		}

		// ������ �߰��� �ε��� ��� �� ����
		rear = (rear + 1) % maxSize;
		data[rear] = value;
	}

	// ������ ���� �Լ�
	bool Dequeue(int& outValue)
	{
		if (IsEmpty())
		{
			std::cout << "Error: ť�� ����ֽ��ϴ�.\n";
			return false;
		}

		// ������ ������ ��ġ�� ã�Ƽ� ����
		front = (front + 1) % maxSize;
		outValue = data[front];
		return true;
	}

	// ��� �Լ�
	void Print()
	{
		std::cout << "ť ����: ";
		int max = (front < rear) ? rear : rear + maxSize;
		for (int i = front + 1; i <= max; ++i)
		{
			std::cout << data[i % maxSize] << " ";
		}

		std::cout << "\n";
	}

private:
	// �����Ͱ� ��µǴ� ��ġ
	int front = 0;

	// �����Ͱ� �ԷµǴ� ��ġ
	int rear = 0;

	// ������ �����
	int data[maxSize];
};
