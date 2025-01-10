#pragma once

template<typename KeyType, typename ValueType>
class Pair
{
public:
	Pair()
		: key(), value()
	{
	}

	Pair(KeyType key, ValueType value)
		: key(key), value(value)
	{
	}

	// == ������ �����ε�
	bool operator==(const Pair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	}

	// != ������ �����ε�
	bool operator!=(const Pair<KeyType, ValueType>& other)
	{
		return key != other.key || value != other.value;
	}

public:
	// Ű (Key)
	KeyType key;

	// �� (Value
	ValueType value;
};
