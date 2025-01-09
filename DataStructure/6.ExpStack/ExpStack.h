#pragma once

#include <iostream>

// ���� �ִ� ����
const int maxCount = 100;

// ����ġ�� �����ϴ� ���� Ŭ����
class ExpStack
{
public:
	ExpStack()
	{
		// �迭 0.0f�� �ʱ�ȭ
		memset(data, 0.0f, sizeof(float) * maxCount);
	}

	// ������ ���� �Լ�
	void Clear()
	{
		count = 0;
	}

	// ���ÿ� ����� ����� �� ��ȯ �Լ�
	int Count() const
	{
		return count;
	}

	// ������ ������� Ȯ���ϴ� �Լ�
	bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ �߰� �Լ� (Push)
	void Push(float exp)
	{
		// ������ ���� á���� Ȯ��
		if (count == maxCount)
		{
			// �α�
			std::cout << "������ ���� ���� ������ ���忡 �����߽��ϴ�.\n";
			return;
		}

		// ����ġ ����
		data[count] = exp;

		// ����� ������ �� ���� ó��
		++count;
	}

	//// ������ ���� �� ��ȯ �Լ� (Pop)
	//float Pop()
	//{
	//	// ������ ������� ����
	//	if (IsEmpty())
	//	{
	//		// �α�
	//		std::cout << "������ �� ������ ��ȯ�� �����߽��ϴ�.\n";
	//		return 0.0f;
	//	}

	//	// ������ �ϳ� ���ҽ�Ű�� ���� ��ȯ
	//	--count;
	//	return data[count];
	//}

	// ������ ���� �� ��ȯ �Լ� (Pop)
	bool Pop(float& outValue)
	{
		// ������ ������� ����
		if (IsEmpty())
		{
			// �α�
			std::cout << "������ �� ������ ��ȯ�� �����߽��ϴ�.\n";
			return false;
		}

		// ������ �ϳ� ���ҽ�Ű�� ���� ��ȯ
		--count;
		outValue = data[count];
		return true;
	}

private:
	// ������ �����
	float data[maxCount];

	// ���ÿ� ����� ����� �� (top / head)
	int count = 0;
};
