#pragma once

#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// ��Ī ����
	using Entry = Pair<std::string, std::string>;

public:
	// ����� �⺻ ������ ����
	HashTable() = default;

	// ����� �⺻ �Ҹ��� ����
	~HashTable() = default;

	void Add(const std::string& key, const std::string& value);
	void Delete(const std::string& key);
	bool Find(const std::string& key, Entry& outValue);
	void Print();

private:
	// ���� ������� ũ��
	// �ؽ� �浹 ������ ���ؼ� ���� ������� ũ�⸦
	// �Ҽ��� ����ϰ�, ���� ū ���� ����ؾ� �ϴµ�,
	// �������δ� ����Ұ� ����� ���� �ִ�.
	static const int bucketCount = 19;
	std::vector<Entry> table[bucketCount];
};
