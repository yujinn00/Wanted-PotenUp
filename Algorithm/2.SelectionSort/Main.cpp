#include <iostream>

void SelectionSort(int* array, int length)
{
	for (int ix = 0; ix < length - 1; ++ix)
	{
		// �ּڰ��� ������ ����
		int minIndex = ix;
		for (int jx = ix + 1; jx < length; ++jx)
		{
			// ��
			if (array[jx] < array[minIndex])
			{
				minIndex = jx;
			}
		}

		// �� �ٲٱ�
		std::swap<int>(array[ix], array[minIndex]);
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
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// �迭 ����
	int length = sizeof(array) / sizeof(int);

	// ���
	std::cout << "���� ���� �� �迭: ";
	PrintArray(array, length);

	// ����
	SelectionSort(array, length);

	// ���
	std::cout << "���� ���� �� �迭: ";
	PrintArray(array, length);

	return 0;
}
