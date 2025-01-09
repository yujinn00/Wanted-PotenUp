#include <iostream>
#include "Stack.h"
#include <stdlib.h>
#include <time.h>

// �ּڰ��� �ִ� ������ ������ ��ȯ�ϴ� �Լ�
int RandomRange(int min, int max)
{
	// ����
	int diff = (max - min) + 1;

	return ((rand() * diff) / (RAND_MAX + 1)) + min;
}

int main()
{
	// ���� �߻��� ����
	srand((unsigned int)time(nullptr));

	// ���� ��ü
	Stack<float> stack;

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "ù ��° ���� ����\n";
	}

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "�� ��° ���� ����\n";
	}

	if (stack.Push((float)RandomRange(10, 300)))
	{
		std::cout << "�� ��° ���� ����\n";
	}

	// ���
	while (!stack.IsEmpty())
	{
		float value;
		if (stack.Pop(value))
		{
			std::cout << "���� ����ġ: " << value << "\n";
		}
	}
}
