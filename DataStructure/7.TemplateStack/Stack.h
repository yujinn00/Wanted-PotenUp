#pragma once

#include <iostream>

template<typename T, int size = 10>
class Stack
{
public:
	Stack()
	{
		memset(data, 0, sizeof(T) * size);
	}

	// �ʱ�ȭ
	void Clear()
	{
		count = 0;
	}

	// ���ÿ� ����� ����� �� ��ȯ
	inline int Count() const
	{
		return count;
	}

	// ������ ������� Ȯ���ϴ� �Լ�
	inline bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ ���� á���� Ȯ���ϴ� �Լ�
	inline bool IsFull() const
	{
		return count == size;
	}

	// ������ ���� �Լ�
	bool Push(T value)
	{
		// ���� ó��
		if (IsFull())
		{
			std::cout << "������ ���� ���� ���忡 �����߽��ϴ�.\n";
			return false;
		}

		// ���� �� ī��Ʈ ����
		data[count] = value;
		++count;
		return true;
	}

	// ������ ���� �� ��� �Լ�
	bool Pop(T& outValue)
	{
		// ���� ó��
		if (IsEmpty())
		{
			std::cout << "������ �� ��¿� �����߽��ϴ�.\n";
			return false;
		}

		// ī��Ʈ ���� �� ������ ��ȯ
		--count;
		outValue = data[count];
		return true;
	}

private:
	// ������ ���� �迭
	T data[size];

	// ���ÿ� ����� ����� �� (top / head)
	int count = 0;
};
