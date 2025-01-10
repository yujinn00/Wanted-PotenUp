#include "HashTable.h"
#include <iostream>

// �ؽ� �Լ� (�߿�)
int GenerateHash(const std::string& keyString)
{
	// ���� ���� ���ڿ� ���� Ȯ��
	//int length = (int)strlen(keyString); // 1

	// ������ Ű
	int hash = 0;
	for (int i = 0; i < (int)keyString.size(); ++i)
	{
		// �ؽ� �Լ� �ٽ� ����
		hash = hash * 31 + keyString[i]; // (���)
	}

	// �ؽ� ���� �ʹ� ũ�� ������ ��ȯ�Ǵ� ��찡 �־ ����� �����
	return hash < 0 ? -hash : hash;
}

void HashTable::Add(const std::string& key, const std::string& value)
{
	// �ε��� ���ϱ�
	int bucketIndex = GenerateHash(key) % bucketCount;

	// ������ ��ġ�� �ִ� �����̳� ��������
	auto& position = table[bucketIndex];

	// �˻� (�ؽ� ���̺��� �ߺ��� ������� ����)
	for (int i = 0; i < int(position.size()); ++i)
	{
		// Ű ��
		//if (strcmp(position[i].key, key) == 0) // 2
		if (position[i].key == key)
		{
			std::cout << "�̹� ���� Ű�� ����Ǿ� �־� ������ �����߽��ϴ�.\n";
			return;
		}
	}

	// ������ ���� (Vector�� push_back() �Լ��� �Ű������� R-Value Reference�� ���޵�)
	position.push_back(Entry(key, value));
}

void HashTable::Delete(const std::string& key)
{
	// �ε��� ���ϱ�
	int bucketIndex = GenerateHash(key) % bucketCount;

	// ������ ��ġ�� �ִ� �����̳� ��������
	auto& position = table[bucketIndex];

	// �˻� (�ؽ� ���̺��� �ߺ��� ������� ����)
	for (int i = 0; i < int(position.size()); ++i)
	{
		// Ű ��
		//if (strcmp(position[i].key, key) == 0) // 3
		if (position[i].key == key)
		{
			position.erase(position.begin() + i);
			std::cout << "Ű: " << key << " �׸��� �����߽��ϴ�.\n";
			return;
		}
	}

	// �˻� ����
	std::cout << "������ �׸��� ã�� ���߽��ϴ�.\n";
}

bool HashTable::Find(const std::string& key, Entry& outValue)
{
	// �ε��� ���ϱ�
	int bucketIndex = GenerateHash(key) % bucketCount;

	// �˻��� ��ġ�� �ִ� �����̳� ��������
	auto& position = table[bucketIndex];

	// ���� ó��
	if (position.size() == 0)
	{
		std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
		return false;
	}

	// �˻�
	for (int i = 0; i < (int)position.size(); ++i)
	{
		// Ű ��
		//if (strcmp(position[i].key, key) == 0) // 4
		if (position[i].key == key)
		{
			// �˻��� �����ϸ�, �� ���
			outValue = position[i];
			return true;
		}
	}

	std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
	return false;
}

void HashTable::Print()
{
	for (int i = 0; i < bucketCount; ++i)
	{
		// �ǳʶٱ�
		if (table[i].size() == 0)
		{
			continue;
		}

		// ���
		for (auto& entry : table[i])
		{
			std::cout << "Ű: " << entry.key << ", ��: " << entry.value << "\n";
		}
	}
}
