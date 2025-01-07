#include <iostream>
#include <array>

template<typename T, size_t size>
class Array
{
public:
	T& operator[](int index)
	{
		return data[index];
	}

	size_t Count() const { return size; };

private:
	T data[size];
};

void Function(Array<int, 10>& array)
{

}

int main()
{
	// 정수형 배열
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 힙 배열
	int* heapArray = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 삭제
	delete[] heapArray;

	// 배열 객체
	Array<int, 10> arrayObject;
	arrayObject[0] = 10;
	arrayObject[1] = 20;
	arrayObject[2] = 30;

	std::cout << arrayObject.Count() << "\n";
	std::cout << arrayObject[2] << "\n";

	// STL array
	std::array<int, 10> stlArray;
	stlArray[0] = 100;
	stlArray[1] = 200;
	stlArray[2] = 300;

	size_t arraySize = stlArray.size();
}
