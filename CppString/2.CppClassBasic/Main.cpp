#include <iostream>

// 메모리 누수 확인을 위한 헤더 파일
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 메모리 누수 코드가 몇 번째 줄인지 확인하기 위한 소스 코드
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define new new
#endif

class Player {
private:
	int x, y;
	int speed;
public:
	Player() : x(0), y(0), speed(1) {
		std::cout << "생성자 호출\n";
	}

	~Player() {
		std::cout << "소멸자 호출\n";
	}

	// 이동할 만큼의 양을 입력 받아서 좌표를 이동시키는 함수
	void Move(int x, int y) { // int x, int y: 벡터
		this->x += x; // this->x: 위치
		this->y += y; // this->y: 위치
	}
};

int main() {
	// 메모리 누수 확인을 위한 소스 코드 (전체 파트 확인)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// 해당 블록으로 가서 정지시킴
	//_CrtSetBreakAlloc(158);

	// 객체 / 개체 / 오브젝트 / 인스턴스
	// 암묵적
	//Player player1;
	// 명시적
	Player player1 = Player(); // 생성자 명시적 호출 선호 !!!!!!!!!!
	player1.Move(10, 20);

	// 동적 할당
	Player* player2 = new Player();
	//delete player2;
	//player2 = nullptr; // delete 키워드로 해제해주고, 그 뒤에 이것까지 해주는 것을 선호 !!!!!!!!!!

	std::cin.get();

	return 0;
}
