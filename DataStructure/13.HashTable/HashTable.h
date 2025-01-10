#pragma once

#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// 별칭 선언
	using Entry = Pair<std::string, std::string>;

public:
	// 명시적 기본 생성자 선언
	HashTable() = default;

	// 명시적 기본 소멸자 선언
	~HashTable() = default;

	void Add(const std::string& key, const std::string& value);
	void Delete(const std::string& key);
	bool Find(const std::string& key, Entry& outValue);
	void Print();

private:
	// 내장 저장소의 크기
	// 해시 충돌 방지를 위해서 내장 저장소의 크기를
	// 소수를 사용하고, 또한 큰 수를 사용해야 하는데,
	// 단점으로는 저장소가 낭비될 수가 있다.
	static const int bucketCount = 19;
	std::vector<Entry> table[bucketCount];
};
