#include <iostream>

// �� ���� ���� ��ȯ�ϴ� �Լ�
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ���� ���� �Լ�
void BubbleSort(int* array, int length)
{
	// ����
	for (int ix = 0; ix < length - 1; ++ix)
	{
		// ���ǽĿ��� ix�� ���� ���� ����ȭ�� ����
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			// �� ���� ��
			if (array[jx] > array[jx + 1])
			{
				// ��ȯ
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

// ��� �Լ�
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << " ";
	}

	std::cout << "\n";
}

int main()
{
	// �ڷ� ����
	int array[] = { 5, 2, 8, 10, 15, 20, 23 };

	// �迭 ����
	int length = sizeof(array) / sizeof(int);

	// ���
	std::cout << "���� ���� �� �迭: ";
	PrintArray(array, length);

	// ����
	BubbleSort(array, length);

	// ���
	std::cout << "���� ���� �� �迭: ";
	PrintArray(array, length);

	return 0;
}
