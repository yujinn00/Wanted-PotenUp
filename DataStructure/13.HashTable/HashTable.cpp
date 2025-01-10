#include "HashTable.h"
#include <iostream>

// 해시 함수 (중요)
int GenerateHash(const std::string& keyString)
{
	// 전달 받은 문자열 길이 확인
	//int length = (int)strlen(keyString); // 1

	// 생성할 키
	int hash = 0;
	for (int i = 0; i < (int)keyString.size(); ++i)
	{
		// 해시 함수 핵심 로직
		hash = hash * 31 + keyString[i]; // (쭝요)
	}

	// 해시 값이 너무 크면 음수가 반환되는 경우가 있어서 양수로 만들기
	return hash < 0 ? -hash : hash;
}

void HashTable::Add(const std::string& key, const std::string& value)
{
	// 인덱스 구하기
	int bucketIndex = GenerateHash(key) % bucketCount;

	// 저장할 위치에 있는 컨테이너 가져오기
	auto& position = table[bucketIndex];

	// 검색 (해시 테이블은 중복을 허용하지 않음)
	for (int i = 0; i < int(position.size()); ++i)
	{
		// 키 비교
		//if (strcmp(position[i].key, key) == 0) // 2
		if (position[i].key == key)
		{
			std::cout << "이미 같은 키가 저장되어 있어 삽입을 실패했습니다.\n";
			return;
		}
	}

	// 데이터 삽입 (Vector의 push_back() 함수의 매개변수는 R-Value Reference로 전달됨)
	position.push_back(Entry(key, value));
}

void HashTable::Delete(const std::string& key)
{
	// 인덱스 구하기
	int bucketIndex = GenerateHash(key) % bucketCount;

	// 삭제할 위치에 있는 컨테이너 가져오기
	auto& position = table[bucketIndex];

	// 검색 (해시 테이블은 중복을 허용하지 않음)
	for (int i = 0; i < int(position.size()); ++i)
	{
		// 키 비교
		//if (strcmp(position[i].key, key) == 0) // 3
		if (position[i].key == key)
		{
			position.erase(position.begin() + i);
			std::cout << "키: " << key << " 항목을 삭제했습니다.\n";
			return;
		}
	}

	// 검색 실패
	std::cout << "삭제할 항목을 찾지 못했습니다.\n";
}

bool HashTable::Find(const std::string& key, Entry& outValue)
{
	// 인덱스 구하기
	int bucketIndex = GenerateHash(key) % bucketCount;

	// 검색할 위치에 있는 컨테이너 가져오기
	auto& position = table[bucketIndex];

	// 예외 처리
	if (position.size() == 0)
	{
		std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
		return false;
	}

	// 검색
	for (int i = 0; i < (int)position.size(); ++i)
	{
		// 키 비교
		//if (strcmp(position[i].key, key) == 0) // 4
		if (position[i].key == key)
		{
			// 검색에 성공하면, 값 출력
			outValue = position[i];
			return true;
		}
	}

	std::cout << "해당 키로 항목을 찾지 못했습니다.\n";
	return false;
}

void HashTable::Print()
{
	for (int i = 0; i < bucketCount; ++i)
	{
		// 건너뛰기
		if (table[i].size() == 0)
		{
			continue;
		}

		// 출력
		for (auto& entry : table[i])
		{
			std::cout << "키: " << entry.key << ", 값: " << entry.value << "\n";
		}
	}
}
