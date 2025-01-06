#include <iostream>
#include <vector>	// ���� �迭
#include <list>		// ���� ����Ʈ

// ���� ���̺귯��
// Vector2 / Vector3 / Vector4

// �ݺ���(Iterator) Ŭ����
template<typename Vector>
class VectorIterator
{
public:
	// Ÿ�� ����
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}

	// ������ ���� ���� ������ �����ε�
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	// �ε��� ������ �����ε�
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// ������ ������ �����ε�
	PointerType operator->()
	{
		return pointer;
	}

	//�� ��ȯ ������ �����ε�
	ReferenceType operator*()
	{
		return *pointer;
	}

	// �� ������ �����ε�
	bool operator==(const VectorIterator& other) const
	{
		return pointer == other.pointer;
	}

	// �� ������ �����ε�
	bool operator!=(const VectorIterator& other) const
	{
		//return pointer != other.pointer;
		return !(*this == other); // ������ ���� �� ������ �����ε��� �̿��� �ڵ�
	}

private:
	PointerType pointer;
};

// ���� �迭 Ŭ����
// ���ø�
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
	{
		// �ʱ� ������ ���� ����
		data = new T[capacity];
	}

	~List()
	{
		// �����Ͱ� ����Ű�� �� �迭 ���� ����
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	// ���� �߰�
	void PushBack(const T& value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����
		data[count] = value;
		
		// ����� ����� �� ���� ó��
		++count;
	}

	// Move �߰�
	void PushBack(T&& value)
	{
		// �ڷḦ �߰��� �� �ִ� ����� ������ �ִ��� Ȯ��
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
		}

		// ���� �迭�� ������ ��ҿ� ���޹��� ������ ����
		data[count] = std::move(value);

		// ����� ����� �� ���� ó��
		++count;
	}

	// ���� �Լ�
	T& At(int index)
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ���� �Լ�
	const T& At(int index) const
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ������ �����ε�
	T& operator[](int index)
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// ������ �����ε�
	const T& operator[](int index) const
	{
		// ���� ó��
		if (index >= count)
		{
			__debugbreak();
		}

		return data[index];
	}

	// Iterator ���� �Լ�
	Iterator begin()
	{
		return Iterator(data);
	}

	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter

	// ��� �� ��ȯ
	int Count() const { return count; }

	// ���� �뷮 ��ȯ
	int Capacity() const { return capacity; }

	// �迭 �ּ� ��ȯ
	T* Data() const { return data; };

private:
	// ������ ������ ������ �� ������ �ø��� �Լ�
	void ReAllocate(int newCapacity)
	{
		// 1. ���ο� �޸� ���� �Ҵ� (Allocate)
		T* newBlock = new T[newCapacity];

		// 2. ������ ������ ����
		//for (int i = 0; i < count; ++i)
		//{
		//	// newBlock[i] = data[i]; // ����: ù ��° ���
		//	newBlock[i] = std::move(data[i]); // ����: �� ��° ���
		//}
		memcpy(newBlock, data, sizeof(T) * count); // ����: �� ��° ���

		// 3. ���� ������ �� �ӽ� ������ ����
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}

private:
	// ������ ���� (���� �Ҵ��� �迭 ����)
	T* data = nullptr;

	// �뷮
	int capacity = 2;

	// �迭 ������ ��
	int count = 0;
};

int main()
{
	// ���� �迭 ��ü ����
	List<int> list;

	//List<int>::ValueType;

	// ���� �߰�
	for (int i = 0; i < 100; ++i)
	{
		list.PushBack(i);
		//list.PushBack(10); // �� �ڵ�� �ٸ� �Լ��� ��µ� (�����ε�)
	}

	char buffer[256];
	snprintf(buffer, 256, "%d, %d\n", list.Count(), list.Capacity()); // 100, 128

	//const int& value = list[100];

	//std::cout << list.Count() << ", " << list.Capacity() << "\n";
	std::cout << buffer;

	// Standard Template Library(STL) ���� �迭
	std::vector<int> vector;
	//{
	//	1, 2, 3, 4, 5
	//};

	// ���� �߰�
	for (int i = 0; i < 100; ++i)
	{
		vector.push_back(i);
		//vector.emplace_back(10); // emplace_back: ������ move() �ø�ƽ �� �� ���
	}

	// �б�
	// Range-Based Loop / Ranged Loop
	// forEach / Foreach
	//for (const auto& item : vector)
	//{
	//	std::cout << item << " ";
	//}

	// �츮�� ���� ���� �迭
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
