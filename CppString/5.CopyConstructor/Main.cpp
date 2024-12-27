#include <iostream>

class Player {
private:
	int x;
	int y;
	char* name;

public:
	Player() : x(0), y(0) {
		size_t length = strlen("Player") + 1;
		name = new char[length];
		strcpy_s(name, length, "Player");
	}

	Player(const char* name, int x, int y) : x(x), y(y) {
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}
	
	// 복사 생성자
	// cpp value category
	// lvalue / rvalue
	Player(const Player& other) {
		std::cout << "Player(const Player& other) called\n";

		x = other.x;
		y = other.y;

		size_t length = strlen(other.name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, other.name);
	}

	~Player() {
		delete[] name;
	}

	void Print() {
		std::cout << "name: " << name << ", x: " << x << ", y: " << y << "\n";
	}
};

int main() {
	Player player1 = Player("Ronnie", 0, 0);
	Player player2 = Player(player1);

	player1.Print();
	player2.Print();
;
	return 0;
}