#include <iostream>
#include <vector>	// 동적 배열
#include <list>		// 연결 리스트

// 수학 라이브러리
// Vector2 / Vector3 / Vector4

// 반복자(Iterator) 클래스
template<typename Vector>
class VectorIterator
{
public:
	// 타입 지정
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{
	}

	// 포인터 전위 증가 연산자 오버로딩
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}

	// 포인터 후위 증가 연산자 오버로딩
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// 포인터 전위 감소 연산자 오버로딩
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}

	// 포인터 후위 감소 연산자 오버로딩
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// 인덱스 연산자 오버로딩
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// 포인터 연산자 오버로딩
	PointerType operator->()
	{
		return pointer;
	}

	//값 반환 연산자 오버로딩
	ReferenceType operator*()
	{
		return *pointer;
	}

	// 비교 연산자 오버로딩
	bool operator==(const VectorIterator& other) const
	{
		return pointer == other.pointer;
	}

	// 비교 연산자 오버로딩
	bool operator!=(const VectorIterator& other) const
	{
		//return pointer != other.pointer;
		return !(*this == other); // 위에서 만든 비교 연산자 오버로딩을 이용한 코드
	}

private:
	PointerType pointer;
};

// 동적 배열 클래스
// 템플릿
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// 초기 데이터 공간 설정
		data = new T[capacity];
	}

	~List()
	{
		// 포인터가 가리키는 힙 배열 변수 삭제
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	// 원소 추가
	void PushBack(const T& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		data[count] = value;
		
		// 저장된 요소의 수 증가 처리
		++count;
	}

	// Move 추가
	void PushBack(T&& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// 현재 배열의 마지막 요소에 전달받은 데이터 설정
		data[count] = std::move(value);

		// 저장된 요소의 수 증가 처리
		++count;
	}

	// 접근 함수
	T& At(int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 접근 함수
	const T& At(int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 연산자 오버로딩
	T& operator[](int index)
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// 연산자 오버로딩
	const T& operator[](int index) const
	{
		// 예외 처리
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// Iterator 관련 함수
	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter

	// 요소 수 반환
	int Count() const { return count; }

	// 저장 용량 반환
	int Capacity() const { return capacity; }

	// 배열 주소 반환
	T* Data() const { return data; };

private:
	// 저장할 공간이 부족할 때 공간을 늘리는 함수
	void ReAllocate(int newCapacity)
	{
		// 1. 새로운 메모리 공간 할당 (Allocate)
		T* newBlock = new T[newCapacity];

		// 2. 기존의 데이터 복사
		//for (int i = 0; i < count; ++i)
		//{
		//	// newBlock[i] = data[i]; // 복사: 첫 번째 방법
		//	newBlock[i] = std::move(data[i]); // 복사: 두 번째 방법
		//}
		memcpy(newBlock, data, sizeof(T) * count); // 복사: 세 번째 방법

		// 3. 기존 데이터 및 임시 데이터 삭제
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	// 데이터 선언 (힙에 할당할 배열 변수)
	T* data = nullptr;

	// 용량
	int capacity = 2;

	// 배열 원소의 수
	int count = 0;
};

int main()
{
	// 동적 배열 객체 생성
	List<int> list;

	//List<int>::ValueType;

	// 원소 추가
	for (int i = 0; i < 100; ++i)
	{
		list.PushBack(i);
		//list.PushBack(10); // 위 코드와 다른 함수가 출력됨 (오버로딩)
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity()); // 100, 128

	//const int& value = list[100];

	//std::cout << list.Count() << ", " << list.Capacity() << "\n";
	std::cout << buffer;

	// Standard Template Library(STL) 동적 배열
	std::vector<int> vector;
	//{
	//	1, 2, 3, 4, 5
	//};

	// 원소 추가
	for (int i = 0; i < 100; ++i)
	{
		vector.push_back(i);
		//vector.emplace_back(10); // emplace_back: 참조와 move() 시맨틱 둘 다 허용
	}

	// 읽기
	// Range-Based Loop / Ranged Loop
	// forEach / Foreach
	//for (const auto& item : vector)
	//{
	//	std::cout << item << " ";
	//}

	// 우리가 만든 동적 배열
	for (const auto& item : list)
	{
		std::cout << item << " ";
	}

	for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		std::cout << *iterator << " ";
	}

	std::cout << "\n";

	snprintf(buffer, 256, "%d, %d",
		static_cast<int>(vector.size()),
		static_cast<int>(vector.capacity())
	);
	std::cout << buffer;
}
