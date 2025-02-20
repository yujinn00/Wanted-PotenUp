#include <iostream>

// 두 값을 서로 교환하는 함수
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 버블 정렬 함수
void BubbleSort(int* array, int length)
{
	// 정렬
	for (int ix = 0; ix < length - 1; ++ix)
	{
		// 조건식에서 ix를 빼는 것은 최적화를 위함
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			// 두 개씩 비교
			if (array[jx] > array[jx + 1])
			{
				// 교환
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

// 출력 함수
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
	// 자료 집합
	int array[] = { 5, 2, 8, 10, 15, 20, 23 };

	// 배열 길이
	int length = sizeof(array) / sizeof(int);

	// 출력
	std::cout << "버블 정렬 전 배열: ";
	PrintArray(array, length);

	// 정렬
	BubbleSort(array, length);

	// 출력
	std::cout << "버블 정렬 후 배열: ";
	PrintArray(array, length);

	return 0;
}
