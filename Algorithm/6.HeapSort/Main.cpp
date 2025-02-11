#include <iostream>
#include <vector>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �� ���� �Լ�
void Heapify(std::vector<int>& array, int length, int ix)
{
	while (true)
	{
		// �� ������ �����ϴ� �ε���
		int largest = ix;

		// ���� �ڼ� �ε���
		int left = 2 * ix + 1;

		// ������ �ڼ� �ε���
		int right = 2 * ix + 2;

		if (left < length && array[left] > array[largest])
		{
			largest = left;
		}

		if (right < length && array[right] > array[largest])
		{
			largest = right;
		}

		if (largest == ix)
		{
			break;
		}

		std::swap(array[ix], array[largest]);
		ix = largest;
	}
}

// �� ���� �Լ�
void HeapSort(std::vector<int>& array)
{
	// ��ü ũ��
	int length = (int)array.size();

	// �� ����
	for (int ix = length / 2 - 1; ix >= 0; --ix)
	{
		// �� ����
		Heapify(array, length, ix);
	}

	// ����
	for (int ix = length - 1; ix > 0; --ix)
	{
		std::swap(array[0], array[ix]);
		Heapify(array, ix, 0);
	}
}

// �迭 ��� �Լ�
void PrintArray(std::vector<int>& array)
{
	for (int ix = 0; ix < array.size(); ++ix)
	{
		std::cout << array[ix] << (ix < array.size() - 1 ? ", " : "");
	}

	std::cout << "\n";
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �ڷ� ����
	std::vector<int> array = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// ���� �� ���
	std::cout << "�� ���� �� �迭: ";
	PrintArray(array);

	// ����
	HeapSort(array);

	// ���� �� ���
	std::cout << "�� ���� �� �迭: ";
	PrintArray(array);

	return 0;
}
