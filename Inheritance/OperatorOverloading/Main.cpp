#include "Vector2.h"

// << ������ �����ε�
// ���� �����Ͼ ���� (���� �ϳ� ����ϴµ�, ���� �ʿ�� ����)
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << ", " << vector.GetY() << ")\n";
//	return os;
//}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	//Vector2 result = position.Multiply(speed);
	//Vector2 result = position.operator*(speed); // �Ʒ� �ڵ��� ��ü��
	Vector2 result = position * speed;
	result[0]; // ���ڱ� �̰� ���� ?

	// �Ʒ� 3���� ����� << ������ �����ε� �� �ϸ� ������ ��
	std::cout << position << "\n";
	std::cout << speed << "\n";
	std::cout << result << "\n";
}