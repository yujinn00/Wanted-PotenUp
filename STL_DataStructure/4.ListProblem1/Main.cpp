#include <iostream>
#include <string>
#include <list>

struct Vector2
{
	Vector2(const std::string& name, int x, int y)
		: name(name), x(x), y(y)
	{
	}

	std::string name;
	int x = 0;
	int y = 0;
};

std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
	return os << vector.name << " (" << vector.x << "," << vector.y << ")\n";
}

void Print(std::list<Vector2>& polygon)
{
	std::cout << "-----도형 출력 시작-----\n";
	for (auto& position : polygon)
	{
		std::cout << position;
	}
	std::cout << "-----도형 출력 끝-----\n";
}

int main()
{
	// 리스트 생성
	std::list<Vector2> polygon;

	// 점 추가
	polygon.emplace_back(Vector2("A", 50, 200));
	polygon.emplace_back(Vector2("B", 20, 80));
	polygon.emplace_back(Vector2("C", 75, 10));
	polygon.emplace_back(Vector2("D", 130, 80));
	polygon.emplace_back(Vector2("E", 100, 200));

	// 출력
	Print(polygon);

	std::cin.get();
}
