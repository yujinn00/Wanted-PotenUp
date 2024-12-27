#pragma once

#include <iostream>

// 2���� ���� Ŭ����
class Vector2
{
private:
	float x;
	float y;
public:
	Vector2();
	Vector2(float x, float y);

	// ���ϱ�
	Vector2 Add(const Vector2& other);

	// ���ϱ�
	Vector2 Multiply(const Vector2& other);

	// ������ �����ε�
	// Ư���� �Լ�
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	float operator[](int index);
	
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.GetX() << ", " << vector.GetY() << ")\n";
		return os;
	}

	// Getter & Setter
	float GetX() const;
	float GetY() const;
};
