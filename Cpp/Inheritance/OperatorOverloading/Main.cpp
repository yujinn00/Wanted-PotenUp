#include "Vector2.h"

// << 연산자 오버로딩
// 오버 엔지니어링 금지 (굳이 하나 출력하는데, 만들 필요는 없음)
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
	//Vector2 result = position.operator*(speed); // 아래 코드의 실체임
	Vector2 result = position * speed;
	result[0]; // 갑자기 이건 머지 ?

	// 아래 3개의 출력은 << 연산자 오버로딩 안 하면 에러가 뜸
	std::cout << position << "\n";
	std::cout << speed << "\n";
	std::cout << result << "\n";
}