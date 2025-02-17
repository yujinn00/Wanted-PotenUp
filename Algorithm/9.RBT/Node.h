#pragma once

// �޸� ���� �Լ�
template<typename T>
void SafeDelete(T*& t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// ��� ���� ������
enum class Color
{
	Red,
	Black
};

// ��� Ŭ����
class Node
{
public:
	// ������ �� �Ҹ���
	Node(int data = 0, Color color = Color::Red);
	~Node() = default;

	// ������
	inline const int Data() const { return data; }
	inline void SetData(int newData) { data = newData; }

	// ����
	inline const Color GetColor() const { return color; }
	inline void SetColor(Color newColor) { color = newColor; }
	const char* ColorString() const;

	// �θ� ���
	inline Node* Parent() const { return parent; };
	inline void SetParent(Node* newParent) { parent = newParent; }

	// ���� �ڽ� ���
	inline Node* Left() const { return left; };
	inline void SetLeft(Node* newLeft) { left = newLeft; }

	// ������ �ڽ� ���
	inline Node* Right() const { return right; };
	inline void SetRight(Node* newRight) { right = newRight; }

private:
	// ������
	int data = 0;

	// ����
	Color color = Color::Red;

	// �θ� ���
	Node* parent = nullptr;

	// ���� �ڽ� ���
	Node* left = nullptr;

	// ������ �ڽ� ���
	Node* right = nullptr;
};
